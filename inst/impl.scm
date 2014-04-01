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
		  ((f) "af.lsb")
		  ((b) "bc.msb")
		  ((c) "bc.lsb")
		  ((d) "de.msb")
		  ((e) "de.lsb")
		  ((h) "hl.msb")
		  ((l) "hl.lsb")
		  ((af) "af.pair")
		  ((bc) "bc.pair")
		  ((de) "de.pair")
		  ((hl) "hl.pair")
		  ((ix) "ix")
		  ((iy) "iy")
		  ((sp) "sp")
		  ((pc) "pc"))))

(define (mem-read-8 . addr)
  (string-append "mem_read8(mem, " (apply string-append addr) ")"))
(define (mem-read-16 . addr)
  (string-append "mem_read16(mem, " (apply string-append addr) ")"))
(define (mem-write-8 addr value)
  (string-append "mem_write8(mem, " addr ", " value ")"))
(define (mem-write-16 addr value)
  (string-append "mem_write16(mem, " addr ", " value ")"))

(define-instruction (nop))

;; 8-bit-load-instructions
(define-instruction (ld r r2)
  (register 'r) " = " (register 'r2) ";" "\n")
(define-instruction (ld r n)
  (register 'r) " = n;" "\n")
(define-instruction (ld r (hl))
  (register 'r) " = " (mem-read-8 (register 'hl)) ";" "\n")
(define-instruction (ld r (+ ix d))
  (register 'r) " = " (mem-read-8 (register 'ix) "+d") ";" "\n")
(define-instruction (ld r (+ iy d))
  (register 'r) " = " (mem-read-8 (register 'iy) "+d") ";" "\n")
(define-instruction (ld (hl) r)
  (mem-write-8 (register 'hl) (register 'r)) ";" "\n")
(define-instruction (ld (+ ix d) r)
  (mem-write-8 (string-append (register 'ix) "+d") (register 'r)) ";" "\n")
(define-instruction (ld (+ iy d) r)
  (mem-write-8 (string-append (register 'iy) "+d") (register 'r)) ";" "\n")
(define-instruction (ld (hl) n)
  (mem-write-8 (register 'hl) "n") ";" "\n")
(define-instruction (ld (+ ix d) n)
  (mem-write-8 (string-append (register 'ix) "+d") "n") ";" "\n")
(define-instruction (ld (+ iy d) n)
  (mem-write-8 (string-append (register 'iy) "+d") "n") ";" "\n")
(define-instruction (ld a (bc))
  (register 'a) " = " (mem-read-8 (register 'bc)) ";" "\n")
(define-instruction (ld a (de))
  (register 'a) " = " (mem-read-8 (register 'de)) ";" "\n")
(define-instruction (ld a (nn))
  (register 'a) " = " (mem-read-8 "nn") ";" "\n")
(define-instruction (ld (bc) a)
  (mem-write-8 (register 'bc) (register 'a)) ";" "\n")
(define-instruction (ld (de) a)
  (mem-write-8 (register 'de) (register 'a)) ";" "\n")
(define-instruction (ld (nn) a)
  (mem-write-8 "nn" (register 'a)) ";" "\n")
;; TODO the last four

;; 16-bit-load-instructions
(define-instruction (ld dd nn)
  (register 'dd) " = nn;" "\n")
(define-instruction (ld ix nn)
  (register 'ix) " = nn;" "\n")
(define-instruction (ld iy nn)
  (register 'iy) " = nn;" "\n")
(define-instruction (ld hl nn)
  ;; this might be faster as h=b[0];l=b[1], but it's not possible with the current system
  (register 'hl) " = nn;" "\n")
(define-instruction (ld dd (nn))
  (register 'dd) " = " (mem-read-16 "nn") ";" "\n")
(define-instruction (ld ix (nn))
  (register 'ix) " = " (mem-read-16 "nn") ";" "\n")
(define-instruction (ld iy (nn))
  (register 'iy) " = " (mem-read-16 "nn") ";" "\n")
(define-instruction (ld (nn) hl)
  (mem-write-16 "nn" (register 'hl)) ";" "\n")
(define-instruction (ld (nn) dd)
  (mem-write-16 "nn" (register 'dd)) ";" "\n")
(define-instruction (ld (nn) ix)
  (mem-write-16 "nn" (register 'ix)) ";" "\n")
(define-instruction (ld (nn) iy)
  (mem-write-16 "nn" (register 'iy)) ";" "\n")
(define-instruction (ld sp hl)
  (register 'sp) " = " (register 'hl) ";" "\n")
(define-instruction (ld sp ix)
  (register 'sp) " = " (register 'ix) ";" "\n")
(define-instruction (ld sp iy)
  (register 'sp) " = " (register 'iy) ";" "\n")
(define-instruction (push qq)
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'qq)) ";" "\n")
(define-instruction (push ix)
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'ix)) ";" "\n")
(define-instruction (push iy)
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'iy)) ";" "\n")
(define-instruction (pop qq)
  (register 'qq) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (pop ix)
  (register 'ix) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (pop iy)
  (register 'iy) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")

;; exchange-block-transfer-search-instructions
(define-instruction (ex de hl)
  "nn = " (register 'de) ";" "\n"
  (register 'de) " = " (register 'hl) ";" "\n"
  (register 'hl) " = nn" ";" "\n")

;; 8-bit-arithmetic-instructions
(define-instruction (add n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (add (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (add (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (add (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (register 'a) " = xy;" "\n")
;; TODO: ADC
(define-instruction (adc n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x + y + " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_ADC8;" "\n"
  (register 'a) " = xy;" "\n")
;; SUB
(define-instruction (sub n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sub (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sub (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sub (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'a) " = xy;" "\n")
;; INC
(define-instruction (inc r)
  "x = " (register 'r) ";" "\n"
  "y = 1;" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (register 'r) " = xy;" "\n")
(define-instruction (inc (hl))
  "x = " (mem-read-8 (register 'hl)) ";" "\n"
  "y = 1;" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (mem-write-8 (register 'hl) "xy") ";" "\n")
;; DEC
(define-instruction (dec r)
  "x = " (register 'r) ";" "\n"
  "y = 1;" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'r) " = xy;" "\n")
(define-instruction (dec (hl))
  "x = " (mem-read-8 (register 'hl)) ";" "\n"
  "y = 1;" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (mem-write-8 (register 'hl) "xy") ";" "\n")
;; CP
(define-instruction (cp n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n")
(define-instruction (cp (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n")
(define-instruction (cp (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n")
(define-instruction (cp (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n")


;; 16-bit-arithmetic-instructions
(define-instruction (add hl dd)
  (register 'hl) " += " (register 'dd) ";" "\n")
;;(define-instruction (add hl nn)
;;  (register 'hl) " += nn;" "\n")
;; INC
(define-instruction (inc dd)
  (register 'dd) "++;" "\n")
(define-instruction (inc ix)
  (register 'ix) "++;" "\n")
(define-instruction (inc iy)
  (register 'iy) "++;" "\n")


;; jump instructions
(define-instruction (jp nn)
  (register 'pc) " = nn;" "\n")
(define-instruction (jp nz nn)
  "if(!(" (register 'f) "&FLAG_Z)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")

;; call and return group

(define-instruction (ret)
  (register 'pc) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (call nn)
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = nn;" "\n")
;; Description: The current contents of the Program Counter (PC) are pushed onto the top
;; of the external memory stack. The operands nn are then loaded to the PC to
;; point to the address in memory where the first Op Code of a subroutine is to
;; be fetched. At the end of the subroutine, a RETurn instruction can be used
;; to return to the original program flow by popping the top of the stack back
;; to the PC. The push is accomplished by first decrementing the current
;; contents of the Stack Pointer (register pair SP), loading the high-order byte
;; of the PC contents to the memory address now pointed to by the SP; then
;; decrementing SP again, and loading the low order byte of the PC contents
;; to the top of stack.
;; Because this is a 3-byte instruction, the Program Counter was incremented
;; by three before the push is executed.

;; 
(define-instruction (out (n) a)
  ;; TODO: implement this
  )
