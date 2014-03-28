(use srfi-1)
(include "inst.scm")

;;;;;;;;;;
;; general utility procedures

(define (filtering-map f l)
  (filter (lambda (i) i) (map f l)))

(define (replace-first list this that)
  (if (null? list)
      '()
      (if (equal? (car list) this)
	  (cons that (cdr list))
	  (cons (car list) (replace-first (cdr list) this that)))))

(define (deep-replace s this that)
  (if (symbol? s)
      (if (equal? s this) that s)
      (map (lambda (s) (deep-replace s this that)) s)))

(define (group-by equal? elements)
  (define (group-insert groups elt equal?)
    (if (null? groups)
	(list (list elt))
	(if (equal? elt (first (car groups)))
	    (cons (cons elt (car groups)) (cdr groups))
	    (cons (car groups)
		  (group-insert (cdr groups) elt equal?)))))
  (define (group-by* groups elements equal?)
    (if (null? elements)
	groups
	(group-by* (group-insert groups (car elements) equal?) (cdr elements) equal?)))
  (group-by* '() elements equal?))

(define (bit? b)
  (and (number? b) (or (= 0 b) (= 1 b))))

(define (translate-binary b)
  (define (binary* b)
    (if (null? b)
	0
	(+ (car b) (* 2 (binary* (cdr b))))))
  (binary* (reverse b)))

(define (hex n)
  (list-ref '("0" "1" "2" "3" "4" "5" "6" "7" "8" "9" "A" "B" "C" "D" "E" "F") (modulo n 16)))
(define (hex8 nn)
  (string-append "0x" (hex (quotient nn 16)) (hex nn)))
(define (hex16 nnnn)
  (string-append "0x" (hex (quotient nnnn 4096)) (hex (quotient nnnn 256)) (hex (quotient nnnn 16)) (hex
 nnnn)))

;;;;;;;;;;
;; main

(define (expand-helper-1 r-sym opcode-specification)
  ;; abstract out r from the opcode-spec and (r r r) from the bit pattern
  (let ((mnemonic (list-ref opcode-specification 0))
	(t-cycles (list-ref opcode-specification 1))
	(bit-patterns (cddr opcode-specification)))
    (lambda (r rrr)
      (define (replace-bit-pattern pat)
	(if (>= (length pat) 3)
	    (if (equal? (list (first pat) (second pat) (third pat))
			(list r-sym r-sym r-sym))
		(append rrr (cdddr pat))
		(cons (car pat) (replace-bit-pattern (cdr pat))))
	    pat))
      (cons (cons (car mnemonic) (deep-replace (cdr mnemonic) r-sym r))
	    (cons t-cycles
		  (map replace-bit-pattern bit-patterns))))))

(define (expand-helper-2 nd-sym opcode-specification)
  ;; abstract out r from the opcode-spec and (r r r) from the bit pattern
  (let ((mnemonic (list-ref opcode-specification 0))
	(t-cycles (list-ref opcode-specification 1))
	(bit-patterns (cddr opcode-specification)))
    (lambda (nd nd-bits)
      (cons (replace-first mnemonic nd-sym nd)
	    (cons t-cycles
		  (replace-first bit-patterns
				 (list nd-sym nd-sym nd-sym nd-sym
				       nd-sym nd-sym nd-sym nd-sym)
				 nd-bits))))))

(define (expand-helper-3 dd-sym opcode-specification)
  ;; abstract out dd from the opcode-spec and (d d) from the bit pattern
  (let ((mnemonic (list-ref opcode-specification 0))
	(t-cycles (list-ref opcode-specification 1))
	(bit-patterns (cddr opcode-specification)))
    (lambda (dd dd-bits)
      (define (replace-bit-pattern pat)
	(if (>= (length pat) 2)
	    (if (equal? (list (first pat) (second pat))
			(list dd-sym dd-sym))
		(append dd-bits (cddr pat))
		(cons (car pat) (replace-bit-pattern (cdr pat))))
	    pat))
      (cons (cons (car mnemonic) (deep-replace (cdr mnemonic) dd-sym dd))
	    (cons t-cycles
		  (map replace-bit-pattern bit-patterns))))))

(define (expand-opcode opcode-specification)
  ;; turn an opcode-specification into a list of opcode-specifications
  ;; by expanding the values of r and r2 into every possible register combination
  (let ((mnemonic (list-ref opcode-specification 0))
	(t-cycles (list-ref opcode-specification 1))
	(bit-patterns (cddr opcode-specification)))
    (assert (every (lambda (pat) (= 8 (length pat))) bit-patterns))
    
    (let ((r-expanded (list opcode-specification)))
      (define (perform-expander expander-helper sym table)
	(if (member sym (cdr mnemonic))
	    (apply append
		   (map (lambda (opcode-specification)
			  (let ((expander (expander-helper sym opcode-specification)))
			    (map (lambda (entry) (expander (first entry)
							   (second entry)))
				 table)))
			r-expanded))
	    r-expanded))
      
      (set! r-expanded (perform-expander expand-helper-1 'r register-table))
      (set! r-expanded (perform-expander expand-helper-1 'r2 register-table))
      (set! r-expanded (perform-expander expand-helper-3 'dd dd-table))
      (set! r-expanded (perform-expander expand-helper-3 'qq qq-table))
      (set! r-expanded (perform-expander expand-helper-3 'pp pp-table))
      (set! r-expanded (perform-expander expand-helper-3 'rr rr-table))
      (set! r-expanded (perform-expander expand-helper-1 'cc cc-table))
      (set! r-expanded (perform-expander expand-helper-1 'tt tt-table))
      
      r-expanded)))

(define (disassembler opcode-group)
  (define (case-command-for-opcode opcode bytes-consumed)
    (let* ((instruction (first opcode))
	   (bytes (cddr opcode)))
      (string-append
       "if(size < " (number->string (length (cddr opcode))) ") return -1;" "\n"
      (apply string-append
       (map (let ((seen-n #f)
		  (i bytes-consumed))
	      (lambda (byte)
		(cond ((equal? byte '(d d d d d d d d))
		       (set! i (+ 1 i))
		       (string-append
			"d = ((signed char*)data)["(number->string i)"];" "\n"))
		      ((equal? byte '(e e e e e e e e))
		       (set! i (+ 1 i)) ;; assumes we can't have a d and an e together
		       (string-append
			"d = ((signed char*)data)["(number->string i)"];;" "\n"))
		      ((equal? byte '(n n n n n n n n))
		       (if seen-n
			   ""
			   (if (or (member 'nn (cdr instruction))
				   (member '(nn) (cdr instruction)))
			       (begin
				 (set! seen-n #t)
				 (set! i (+ 2 i))
				 (string-append "nn = data["(number->string (- i 1))"] | data["(number->string i)"] << 8;" "\n"))
			       (begin
				 (set! i (+ 1 i))
				 (string-append "n = data["(number->string i)"];" "\n")))))
		      (else (assert (every bit? byte))
			    ""))))
	    bytes)))))
  (define (t-cycles-for-opcode opcode)
    ;; doesn't handle conditional time instructions
    (number->string (apply + (second opcode))))
  (define (bytes-consumed-by-opcode opcode)
    (number->string (length (cddr opcode))))
  (define (printf-command-for-opcode opcode)
    (define (printf-format-string sym)
      (cond ((equal? sym 'nn)
	     "0x%04X")
	    ((equal? sym '(nn))
	     "(0x%04X)")
	    ((equal? sym 'n)
	     "0x%02X")
	    ((equal? sym '(n))
	     "(0x%02X)")
	    ((equal? sym 'ee)
	     "+%d")
	    ((equal? sym 'rr-)
	     "r")
	    ((equal? sym 'ir)
	     "i")
	    ((equal? sym 'af-)
	     "af'")
	    ((and (list? sym)
		  (equal? (car sym) '+)
		  (equal? (cadr sym) 'ix))
	     "(ix+%d)")
	    ((and (list? sym)
		  (equal? (car sym) '+)
		  (equal? (cadr sym) 'iy))
	     "(iy+%d)")
	    ((symbol? sym)
	     (symbol->string sym))
	    ((number? sym)
	     (number->string sym))
	    ((or (equal? sym '(sp))
		 (equal? sym '(hl))
		 (equal? sym '(bc))
		 (equal? sym '(de))
		 (equal? sym '(ix))
		 (equal? sym '(iy))
		 (equal? sym '(c)))
	     (string-append "(" (symbol->string (car sym)) ")"))
	    (else
	     (print sym)
	     (assert (and 'fail #f)))))
    (define (sym->var sym)
      (cond ((or (equal? sym 'nn)
		 (equal? sym '(nn))) "nn")
	    ((or (equal? sym 'n)
		 (equal? sym '(n))) "n")
	    ((or ;;(equal? sym 'd) ;; this is the register d
		 (and (list? sym) (member 'd sym))) "d")
	    ((equal? sym 'ee)
	     "d")
	    (else #f)))
    (let* ((instruction (first opcode))
	   (nmemonic (symbol->string (first instruction))))
      (string-append
       "printf(\"" nmemonic " "
       (apply string-append (intersperse (map printf-format-string (cdr instruction)) ","))
       "\\n\""
       (begin
	 (define (touch-up-list l)
	   (if (null? l) l (cons "" l)))
	 (apply string-append (intersperse (touch-up-list (filtering-map sym->var (cdr instruction))) ", ")))
       ");" "\n")))
  ;; it is guaranteed that all opcodes have been expanded
  ;; and share the same first byte
  (let ((pat (third (first opcode-group))))
    (assert (every bit? pat))
    (let ((opcode (hex8 (translate-binary pat))))
      
      ;; is this a group of instructions specified by two-bytes
      (cond ((> (length opcode-group) 1)
	     (assert (every (lambda (opcode-spec)
			      (every bit? (fourth opcode-spec)))
			    opcode-group))
	     ;; the second byte is guaranteed to work now
	     (define (subgroup-switch opcode-spec)
	       (let* ((second-byte (second (cddr opcode-spec)))
		      (opcode (hex8 (translate-binary second-byte))))
		 (string-append "case " opcode ":" "\n"
				(case-command-for-opcode opcode-spec 1)
				(printf-command-for-opcode opcode-spec)
				"return " (bytes-consumed-by-opcode opcode-spec) ";" "\n")))
	     (define (bitwise-op-opcode? opcode-spec)
	       (let* ((first-byte (first (cddr opcode-spec)))
		      (second-byte (second (cddr opcode-spec))))
		 (or (and (or (equal? '(1 1 1 1 1 1 0 1) first-byte) ;; FD
			      (equal? '(1 1 0 1 1 1 0 1) first-byte)) ;; DD
			  (equal? '(1 1 0 0 1 0 1 1) second-byte)) ;; CB
		     ;;(and (equal? '(1 1 0 0 1 0 1 1) first-byte) ;; CB
		     ;;(equal? '(0 0 0 1 1) (take second-byte 5)))))) ;; 18 up to 1F
		     )))
	     (define (negate p) (lambda (x) (not (p x))))
	     (let ((normal-ops (filter (negate bitwise-op-opcode?) opcode-group))
		   (bitwise-ops (filter bitwise-op-opcode? opcode-group)))
	     (string-append "case " opcode ":" "\n"
			    "if(size < 2) return -1;" "\n"
			    "switch(data[1]) {" "\n"
			    (apply string-append (map subgroup-switch normal-ops))
			    (if (not (null? bitwise-ops))
				"// BITWISE OPS HERE\n"
				"")
			    "default:" "\n"
			    "return -1;" "\n"
			    "}" "\n"
			    )))
	     (else
	      (string-append "case " opcode ":" "\n"
			     (case-command-for-opcode (first opcode-group) 0)
			     (printf-command-for-opcode (first opcode-group))
			     "return " (bytes-consumed-by-opcode (first opcode-group)) ";" "\n"))))))

(define all-instructions (append 8-bit-load-instructions
				 16-bit-load-instructions
				 exchange-block-transfer-search-instructions
				 8-bit-arithmetic-instructions
				 general-purpose-control-instructions
				 16-bit-arithmetic-instructions
				 rotate-and-shift-instructions ;; hard
				 jump-instructions
				 call-and-return-instructions
				 input-output-instructions
				 ))

(define current-instruction-set
  (case (with-input-from-string
	    (cadddr (cdr (command-line-arguments))) ;; command line parameters will be -q then dis.scm THEN the atom
	  read)
    ((8-bit-load-instructions) 8-bit-load-instructions)
    ((16-bit-load-instructions) 16-bit-load-instructions)
    ((exchange-block-transfer-search-instructions) exchange-block-transfer-search-instructions)
    ((8-bit-arithmetic-instructions) 8-bit-arithmetic-instructions)
    ((general-purpose-control-instructions) general-purpose-control-instructions)
    ((16-bit-arithmetic-instructions) 16-bit-arithmetic-instructions)
    ((rotate-and-shift-instructions) rotate-and-shift-instructions)
    ((jump-instructions) jump-instructions)
    ((call-and-return-instructions) call-and-return-instructions)
    ((input-output-instructions) input-output-instructions)
    ((all) all-instructions)
    (else (print "Error: invalid command line parameter") '())))

(define expanded-instructions
  (group-by (lambda (op-1 op-2)
	      ;; test if the first byte of their opcode is the same
	      (equal? (third op-1) (third op-2)))
	    (apply append (map expand-opcode current-instruction-set))))

(for-each (lambda (opcode-group)
	    (print (disassembler opcode-group))
	    (newline))
	  expanded-instructions)

(exit)
