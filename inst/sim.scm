(use srfi-1)
(include "inst.scm")
(include "impl.scm")
(include "dis.scm")

;; The initial main difference in this file is the printf bit is changed to
;;   (define (implementation-for-opcode opcode)

;;;;;;;;;;
;; main

(define (expand-helper-1-inst r-sym opcode-specification)
  ;; abstract out r from the opcode-spec and (r r r) from the bit pattern
  (let ((mnemonic (list-ref opcode-specification 0))
	(implementation (cdr opcode-specification)))
    (lambda (r rrr)
      (define (replace-bit-pattern pat)
	(if (>= (length pat) 3)
	    (if (equal? (list (first pat) (second pat) (third pat))
			(list r-sym r-sym r-sym))
		(append rrr (cdddr pat))
		(cons (car pat) (replace-bit-pattern (cdr pat))))
	    pat))
      (cons (cons (car mnemonic) (deep-replace (cdr mnemonic) r-sym r))
	    (deep-replace implementation r-sym r)))))

(define (expand-helper-3-inst dd-sym opcode-specification)
  ;; abstract out dd from the opcode-spec and (d d) from the bit pattern
  (let ((mnemonic (list-ref opcode-specification 0))
	(implementation (cdr opcode-specification)))
    (lambda (dd dd-bits)
      (cons (cons (car mnemonic) (deep-replace (cdr mnemonic) dd-sym dd))
	    (deep-replace implementation dd-sym dd)))))

(define (expand-opcode-implementation opcode-implementation)
  (let ((mnemonic (list-ref opcode-implementation 0))
	(implementation (cdr opcode-implementation)))
    (let ((r-expanded (list opcode-implementation)))
      (define (perform-expander expander-helper sym table)
	(if (member sym (cdr mnemonic))
	    (apply append
		   (map (lambda (opcode-implementation)
			  (let ((expander (expander-helper sym opcode-implementation)))
			    (map (lambda (entry) (expander (first entry)
							   (second entry)))
				 table)))
			r-expanded))
	    r-expanded))
      
      (set! r-expanded (perform-expander expand-helper-1-inst 'r register-table))
      (set! r-expanded (perform-expander expand-helper-1-inst 'r2 register-table))
      (set! r-expanded (perform-expander expand-helper-3-inst 'dd dd-table))
      (set! r-expanded (perform-expander expand-helper-3-inst 'qq qq-table))
      (set! r-expanded (perform-expander expand-helper-3-inst 'pp pp-table))
      (set! r-expanded (perform-expander expand-helper-3-inst 'rr rr-table))
      (set! r-expanded (perform-expander expand-helper-1-inst 'cc cc-table))
      (set! r-expanded (perform-expander expand-helper-1-inst 'tt tt-table))
      (set! r-expanded (perform-expander expand-helper-1-inst 'bb bit-table))
      
      r-expanded)))

(define (simulator opcode-group)
  (define (case-command-for-opcode opcode bytes-consumed)
    (let* ((instruction (first opcode))
	   (bytes (cddr opcode)))
      (string-append
       ;;"if(size < " (number->string (length (cddr opcode))) ") return -1;" "\n"
      (apply string-append
       (map (let ((seen-n #f)
		  (i bytes-consumed))
	      (lambda (byte)
		(cond ((equal? byte '(d d d d d d d d))
		       (set! i (+ 1 i))
		       (string-append
			"d = mem_read8_signed(mem, cpu->pc++);" "\n"))
		      ((equal? byte '(e e e e e e e e))
		       (set! i (+ 1 i)) ;; assumes we can't have a d and an e together
		       (string-append
			"d = mem_read8_signed(mem, cpu->pc++);" "\n"))
		      ((equal? byte '(n n n n n n n n))
		       (if seen-n
			   ""
			   (if (or (member 'nn (cdr instruction))
				   (member '(nn) (cdr instruction)))
			       (begin
				 (set! seen-n #t)
				 (set! i (+ 2 i))
				 (string-append "nn = mem_read16(mem, cpu->pc); cpu->pc += 2;" "\n"))
			       (begin
				 (set! i (+ 1 i))
				 (string-append "n = mem_read8(mem, cpu->pc++);" "\n")))))
		      (else (assert (every bit? byte))
			    ""))))
	    bytes)))))
  (define (t-cycles-for-opcode opcode)
    ;; doesn't handle conditional time instructions
    (number->string (apply + (second opcode))))
  (define (bytes-consumed-by-opcode opcode)
    (number->string (length (cddr opcode))))
  (define (implementation-for-opcode opcode)
    ;; search through the
    (cond ((assoc (first opcode) expanded-instruction-implementations) =>
	   (lambda (has-implementation)
	     (eval (cdr has-implementation))))
	  (else (string-append
		 "unimplemented_instruction(10, mem+cpu->pc-1);" "\n"))))
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
				(implementation-for-opcode opcode-spec)
				"return " (bytes-consumed-by-opcode opcode-spec) ";" "\n")))
	     (define (bitwise-subgroup-switch opcode-spec)
	       (let* ((fourth-byte (fourth (cddr opcode-spec)))
		      (opcode (hex8 (translate-binary fourth-byte))))
		 (string-append "case " opcode ":" "\n"
				(implementation-for-opcode opcode-spec)
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
			    ;;"if(size < 2) return -1;" "\n"
			    "switch(mem_read8(mem, cpu->pc++)) {" "\n"
			    (apply string-append (map subgroup-switch normal-ops))
			    (if (not (null? bitwise-ops))
				(let* ((second-byte (second (cddr (car bitwise-ops))))
				       (opcode (hex8 (translate-binary second-byte))))
				  ;; TODO: assert that they all have the same format
				  ;; DD/FD CB (known) dddddddd 8bits? (test this)
				  (string-append
				   "case " opcode ": // CB bitwise operators" "\n"
				   ;;"  if(size < 4) return -1;" "\n"
				   ;;"  d = ((signed char*)data)[2];" "\n"
				   "d = mem_read8_signed(mem, cpu->pc++);" "\n"
				   "  switch(mem_read8(mem, cpu->pc++)) {" "\n"
				   (apply string-append (map bitwise-subgroup-switch bitwise-ops))
				   "  }" "\n"
				   "\n"))
				"")
			    "default:" "\n"
			    "return -1;" "\n"
			    "}" "\n"
			    )))
	     (else
	      (string-append "case " opcode ":" "\n"
			     (case-command-for-opcode (first opcode-group) 0)
			     (implementation-for-opcode (first opcode-group))
			     "return " (bytes-consumed-by-opcode (first opcode-group)) ";" "\n"))))))

(define expanded-instruction-implementations
  (apply append (map expand-opcode-implementation instruction-implementations)))

;;(print expanded-instruction-implementations)
;;(exit)

(for-each (lambda (opcode-group)
	    (print (simulator opcode-group))
	    (newline))
	  expanded-instructions)

(exit)
