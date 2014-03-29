(define instruction-implementations '())

(define-syntax push!
  (syntax-rules ()
    ((push! <list> <elt>)
     (set! <list> (cons <elt> <list>)))))

(define-syntax define-instruction
  (syntax-rules ()
    ((define-instruction (<opcode> <parameter> ...)
       <implementation> ...)
     (push! instruction-implementations
	    '((<opcode> <parameter> ...) . (string-append <implementation> ...))))))

(define (cpu-accessor a)
  (string-append "cpu" "->" a))

(define (register r)
  (cpu-accessor (case r
		  ((a) "af.msb")
		  ((b) "bc.msb")
		  ((c) "bc.lsb")
		  ((d) "de.msb")
		  ((e) "de.lsb")
		  ((h) "hl.msb")
		  ((l) "hl.lsb")
		  ((bc) "bc.pair")
		  ((de) "de.pair")
		  ((hl) "hl.pair")
		  ((sp) "sp"))))

;; 8-bit-load-instructions
(define-instruction (ld r r2)
  (register 'r) " = " (register 'r2) ";" "\n")
(define-instruction (ld r n)
  (register 'r) " = n;" "\n")

;; 16-bit-load-instructions
(define-instruction (ld dd nn)
  (register 'dd) " = nn;" "\n")

;; 8-bit-arithmetic-instructions
(define-instruction (add n)
  ;; TODO probably wrong
  (register 'a) " += n;" "\n")

;; 16-bit-arithmetic-instructions
(define-instruction (add hl dd)
  (register 'hl) " += " (register 'dd) ";" "\n")
;;(define-instruction (add hl nn)
;;  (register 'hl) " += nn;" "\n")
