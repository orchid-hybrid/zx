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
		  ((af-) "afp.pair")
		  ((bc-) "bcp.pair")
		  ((de-) "dep.pair")
		  ((hl-) "hlp.pair")
		  ((ix) "ix")
		  ((iy) "iy")
		  ((sp) "sp")
		  ((pc) "pc")
		  ((iff1) "iff1")
		  ((iff2) "iff2"))))

(define (mem-read-8 . addr)
  (string-append "mem_read8(mem, " (apply string-append addr) ")"))
(define (mem-read-16 . addr)
  (string-append "mem_read16(mem, " (apply string-append addr) ")"))
(define (mem-write-8 addr value)
  (string-append "mem_write8(mem, " addr ", " value ")"))
(define (mem-write-16 addr value)
  (string-append "mem_write16(mem, " addr ", " value ")"))

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
(define-instruction (ex af af-)
  "nn = " (register 'af) ";" "\n"
  (register 'af) " = " (register 'af-) ";" "\n"
  (register 'af-) " = nn" ";" "\n")
(define-instruction (exx)
  "nn = " (register 'bc) ";" "\n"
  (register 'bc) " = " (register 'bc-) ";" "\n"
  (register 'bc-) " = nn" ";" "\n"
  
  "nn = " (register 'de) ";" "\n"
  (register 'de) " = " (register 'de-) ";" "\n"
  (register 'de-) " = nn" ";" "\n"
  
  "nn = " (register 'hl) ";" "\n"
  (register 'hl) " = " (register 'hl-) ";" "\n"
  (register 'hl-) " = nn" ";" "\n")
(define-instruction (ex (sp) hl) ;; this needs tested
  "nn = " (mem-read-16 (register 'sp)) ";" "\n"
  (mem-write-16 (register 'sp) (register 'hl)) ";" "\n"
  (register 'hl) "= nn" ";" "\n")
(define-instruction (ex (sp) ix)
  "nn = " (mem-read-16 (register 'sp)) ";" "\n"
  (mem-write-16 (register 'sp) (register 'ix)) ";" "\n"
  (register 'ix) "= nn" ";" "\n")
(define-instruction (ex (sp) iy)
  "nn = " (mem-read-16 (register 'sp)) ";" "\n"
  (mem-write-16 (register 'sp) (register 'iy)) ";" "\n"
  (register 'iy) "= nn" ";" "\n")
;; LDI
;; LDIR
;; LDD
;; LDDR
;; CPI
;; CPIR
;; CPD
;; CPDR

;; 8-bit-arithmetic-instructions
(define-instruction (add r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (register 'a) " = xy;" "\n")
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
;; ADC
(define-instruction (adc r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x + y + " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_ADC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (adc n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x + y + " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_ADC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (adc (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x + y + " (register 'f) "&FLAG_C;";" "\n"
  "UPDATE_FLAGS_ADC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (adc (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x + y + " (register 'f) "&FLAG_C;";" "\n"
  "UPDATE_FLAGS_ADC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (adc (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x + y + " (register 'f) "&FLAG_C;";" "\n"
  "UPDATE_FLAGS_ADC8;" "\n"
  (register 'a) " = xy;" "\n")
;; SUB
(define-instruction (sub r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'a) " = xy;" "\n")
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
;; TODO: SBC #############
(define-instruction (sbc r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x - y - " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_SBC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sbc n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x - y - " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_SBC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sbc (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x - y - " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_SBC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sbc (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x - y - " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_SBC8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (sbc (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x - y - " (register 'f) "&FLAG_C;" "\n"
  "UPDATE_FLAGS_SBC8;" "\n"
  (register 'a) " = xy;" "\n")
;; TODO: AND #############
(define-instruction (and r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x & y;" "\n"
  "UPDATE_FLAGS_BIT8(1);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (and n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x & y;" "\n"
  "UPDATE_FLAGS_BIT8(1);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (and (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x & y;" "\n"
  "UPDATE_FLAGS_BIT8(1);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (and (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x & y;" "\n"
  "UPDATE_FLAGS_BIT8(1);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (and (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x & y;" "\n"
  "UPDATE_FLAGS_BIT8(1);" "\n"
  (register 'a) " = xy;" "\n")
;; TODO: OR #############
(define-instruction (or r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x | y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (or n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x | y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (or (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x | y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (or (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x | y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (or (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x | y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
;; TODO: XOR #############
(define-instruction (xor r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x ^ y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (xor n)
  "x = " (register 'a) ";" "\n"
  "y = n;" "\n"
  "xy = x ^ y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (xor (hl))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'hl)) ";" "\n"
  "xy = x ^ y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (xor (+ ix d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "xy = x ^ y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (xor (+ iy d))
  "x = " (register 'a) ";" "\n"
  "y = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "xy = x ^ y;" "\n"
  "UPDATE_FLAGS_BIT8(0);" "\n"
  (register 'a) " = xy;" "\n")
;; CP
(define-instruction (cp r)
  "x = " (register 'a) ";" "\n"
  "y = " (register 'r) ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n")
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
(define-instruction (inc (+ ix d))
  "x = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "y = 1;" "\n"
  "xy = x + y;" "\n"
  "UPDATE_FLAGS_ADD8;" "\n"
  (mem-write-8 (register 'hl) "xy") ";" "\n")
(define-instruction (inc (+ iy d))
  "x = " (mem-read-8 (register 'iy) "+d") ";" "\n"
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
(define-instruction (dec (+ ix d))
  "x = " (mem-read-8 (register 'ix) "+d") ";" "\n"
  "y = 1;" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (mem-write-8 (register 'hl) "xy") ";" "\n")
(define-instruction (dec (+ iy d))
  "x = " (mem-read-8 (register 'iy) "+d") ";" "\n"
  "y = 1;" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (mem-write-8 (register 'hl) "xy") ";" "\n")


;; general-purpose-and-control-instructions
;; DAA
(define-instruction (cpl)
  (register 'a) " = ~" (register 'a) ";" "\n"
  (register 'f) " |= FLAG_H | FLAG_N;" "\n")
(define-instruction (neg)
  "x = 0;" "\n"
  "y = " (register 'a) ";" "\n"
  "xy = x - y;" "\n"
  "UPDATE_FLAGS_SUB8;" "\n"
  (register 'a) " = xy;" "\n")
(define-instruction (ccf)
  "if(" (register 'f)"&FLAG_C" ") {" "\n"
  "  " (register 'f) " |= FLAG_H;"
  "  " (register 'f) " &= ~FLAG_C;" "\n"
  "}" "\n"
  "else {" "\n"
  "  " (register 'f) " &= ~FLAG_H;" "\n"
  "  " (register 'f) " |= FLAG_C;"
  "}" "\n"
  (register 'f) " &= ~FLAG_N;" "\n")
(define-instruction (scf)
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= FLAG_C;" "\n")
(define-instruction (nop))
(define-instruction (halt)
  (register 'pc) "--;" "\n")
;; DI
(define-instruction (di)
  (register 'iff1) " = 0;" "\n"
  (register 'iff2) " = 0;" "\n")
;; EI
(define-instruction (ei)
  (register 'iff1) " = 1;" "\n"
  (register 'iff2) " = 1;" "\n")
;; IM 0
;; IM 1
;; IM 2

;; 16-bit-arithmetic-instructions
(define-instruction (add hl dd)
  ;; TODO flags
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
;; DEC
(define-instruction (dec dd)
  (register 'dd) "--;" "\n")
(define-instruction (dec ix)
  (register 'ix) "--;" "\n")
(define-instruction (dec iy)
  (register 'iy) "--;" "\n")

;; rotate and shift
(define-instruction (rlca)
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= ("(register 'a)"&0x80) ? FLAG_C : 0;" "\n"
  (register 'a) " <<= 1;" "\n"
  (register 'a) " |= (" (register 'f) "&FLAG_C) ? 1 : 0;" "\n")
(define-instruction (rla)
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  "n = " (register 'a) "&0x80;" "\n"
  (register 'a) " <<= 1;" "\n"
  (register 'a) "|= ("(register 'f)"&FLAG_C)?1:0;" "\n"
  "if(n)" "\n"
  "  " (register 'f) " |= FLAG_C;" "\n"
  "else" "\n"
  "  " (register 'f) " &= ~FLAG_C;" "\n")
(define-instruction (rrca)
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= ("(register 'a)"&0x01) ? FLAG_C : 0;" "\n"
  (register 'a) " >>= 1;" "\n"
  (register 'a) " |= (" (register 'f) "&FLAG_C) ? 0x80 : 0;" "\n")
(define-instruction (rra)
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  "n = " (register 'a) "&0x01;" "\n"
  (register 'a) " >>= 1;" "\n"
  (register 'a) "|= ("(register 'f)"&FLAG_C)?0x80:0;" "\n"
  "if(n)" "\n"
  "  " (register 'f) " |= FLAG_C;" "\n"
  "else" "\n"
  "  " (register 'f) " &= ~FLAG_C;" "\n")
;;
(define-instruction (rlc r)
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= ("(register 'r)"&0x80) ? FLAG_C : 0;" "\n"
  (register 'r) " <<= 1;" "\n"
  (register 'r) " |= (" (register 'f) "&FLAG_C) ? 1 : 0;" "\n")
(define-instruction (rlc (hl))
  "n = " (mem-read-8 (register 'hl)) ";" "\n"
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= (n&0x80) ? FLAG_C : 0;" "\n"
  "n <<= 1;" "\n"
  "n |= (" (register 'f) "&FLAG_C) ? 1 : 0;" "\n"
  (mem-write-8 (register 'hl) "n") ";" "\n")
(define-instruction (rlc (+ ix d))
  "n = " (mem-read-8 (register 'hl) "+d") ";" "\n"
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= (n&0x80) ? FLAG_C : 0;" "\n"
  "n <<= 1;" "\n"
  "n |= (" (register 'f) "&FLAG_C) ? 1 : 0;" "\n"
  (mem-write-8 (string-append (register 'ix) "+d") "n") ";" "\n")
(define-instruction (rlc (+ iy d))
  "n = " (mem-read-8 (register 'hl) "+d") ";" "\n"
  (register 'f) " &= ~(FLAG_H|FLAG_N);" "\n"
  (register 'f) " |= (n&0x80) ? FLAG_C : 0;" "\n"
  "n <<= 1;" "\n"
  "n |= (" (register 'f) "&FLAG_C) ? 1 : 0;" "\n"
  (mem-write-8 (string-append (register 'iy) "+d") "n") ";" "\n")
;; RL
;; RRC
;; RR
;; SLA
;; SRA
;; SRL
;; RLD
;; RRD

;; bit set and reset group
;; BIT
(define-instruction (set bb r)
  (register 'r) " |= 1<<" (number->string bb) ";" "\n")

;; jump instructions
(define-instruction (jp nn)
  (register 'pc) " = nn;" "\n")
(define-instruction (jp nz nn)
  "if(!(" (register 'f) "&FLAG_Z)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")
(define-instruction (jp z nn)
  "if((" (register 'f) "&FLAG_Z)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")
(define-instruction (jp nc nn)
  "if(!(" (register 'f) "&FLAG_C)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")
(define-instruction (jp c nn)
  "if((" (register 'f) "&FLAG_C)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")
(define-instruction (jp p nn)
  ;; TODO not sure this is correct
  "if(!(" (register 'f) "&FLAG_S)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")
(define-instruction (jp m nn)
  "if((" (register 'f) "&FLAG_S)) {" "\n"
  "  " (register 'pc) " = nn;" "\n"
  "}" "\n")
;; jp PE/PO/Sgn
(define-instruction (jr ee)
  (register 'pc) " += d;" "\n")
(define-instruction (jr nz ee)
  "if(!(" (register 'f) "&FLAG_Z)) {" "\n"
  "  " (register 'pc) " += d;" "\n")
;; JR C,E
(define-instruction (jp (hl))
  (register 'pc) " = " (mem-read-16 (register 'hl)) ";" "\n")
(define-instruction (jp (ix))
  (register 'pc) " = " (mem-read-16 (register 'ix)) ";" "\n")
(define-instruction (jp (iy))
  (register 'pc) " = " (mem-read-16 (register 'iy)) ";" "\n")
;; DJNZ e

;; call and return group
(define-instruction (call nn)
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = nn;" "\n")
(define-instruction (call z nn)
  "if((" (register 'f) "&FLAG_Z)) {" "\n"
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = nn;" "\n")
(define-instruction (call nz nn)
  "if(!(" (register 'f) "&FLAG_Z)) {" "\n"
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = nn;" "\n")
(define-instruction (call c nn)
  "if((" (register 'f) "&FLAG_C)) {" "\n"
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = nn;" "\n")
(define-instruction (call nc nn)
  "if(!(" (register 'f) "&FLAG_C)) {" "\n"
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = nn;" "\n")
;; RET
(define-instruction (ret)
  (register 'pc) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (ret nz)
  "if(!(" (register 'f) "&FLAG_Z)) {" "\n"
  (register 'pc) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (ret z)
  "if((" (register 'f) "&FLAG_Z)) {" "\n"
  (register 'pc) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (ret c)
  "if((" (register 'f) "&FLAG_C)) {" "\n"
  (register 'pc) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
(define-instruction (ret nc)
  "if(!(" (register 'f) "&FLAG_C)) {" "\n"
  (register 'pc) " = " (mem-read-16 (register 'sp)) ";" "\n"
  (register 'sp) " += 2;" "\n")
;; RETCC
;; RETI
;; RETN
;; RST
(define-instruction (rst tt)
  (register 'sp) " -= 2;" "\n"
  (mem-write-16 (register 'sp) (register 'pc)) ";" "\n"
  (register 'pc) " = " (hex8 tt)";" "\n")


;; 
(define-instruction (out (n) a)
  ;; TODO: implement this
  )
(define-instruction (in a (n))
  ;; TODO: implement this
  )
