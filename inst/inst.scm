 ;; TODO make a test .asm file with all 8-bit-load-instructions

;; r and r2 index into register-table
;; n is an 8 bit integer
;; d is a two's complement displacement integer
;; nn is a 16 bit integer
;; a is the accumulator register
;; ir is the interrupt register
;; rr- is the refresh register [added - suffix to avoid clash with rr expander]
;; af- is used for af' (in general suffix with -)
;; bb is used to denote a bit, can't use b or clobbers the register

;; pg81
;; pg194 - same but different order
(define register-table
  '((a (1 1 1))
    (b (0 0 0))
    (c (0 0 1))
    (d (0 1 0))
    (e (0 1 1))
    (h (1 0 0))
    (l (1 0 1))))

;; pg102
(define dd-table
  '((bc (0 0))
    (de (0 1))
    (hl (1 0))
    (sp (1 1))))

;; pg116
(define qq-table
  '((bc (0 0))
    (de (0 1))
    (hl (1 0))
    (af (1 1))))

;; pg179
;(define ss-table dd-table) ;; just use dd

;; pg182
(define pp-table
  '((bc (0 0))
    (de (0 1))
    (ix (1 0))
    (sp (1 1))))

;; pg182
(define rr-table
  '((bc (0 0))
    (de (0 1))
    (iy (1 0))
    (sp (1 1))))

;; pg239
(define cc-table
  '((nz (0 0 0))
    (z  (0 0 1))
    (nc (0 1 0))
    (c  (0 1 1))
    (po (1 0 0))
    (pe (1 0 1))
    (p  (1 1 0))
    (m  (1 1 1))))

;; pg267
(define tt-table
  '((#x00 (0 0 0))
    (#x08 (0 0 1))
    (#x10 (0 1 0))
    (#x18 (0 1 1))
    (#x20 (1 0 0))
    (#x28 (1 0 1))
    (#x30 (1 1 0))
    (#x38 (1 1 1))))

;; pg225
(define bit-table
  '((0 (0 0 0))
    (1 (0 0 1))
    (2 (0 1 0))
    (3 (0 1 1))
    (4 (1 0 0))
    (5 (1 0 1))
    (6 (1 1 0))
    (7 (1 1 1))))

(define 8-bit-load-instructions
  '(((ld r r2) (4)
     (0 1 r r r r2 r2 r2))
    
    ((ld r n) (4 3)
     (0 0 r r r 1 1 0)
     (n n n n n n n n))
    
    ((ld r (hl)) (4 3)
     (0 1 r r r 1 1 0))
    
    ((ld r (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 1 r r r 1 1 0)
     (d d d d d d d d))
    
    ((ld r (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD ;; N.B. error on pg85
     (0 1 r r r 1 1 0)
     (d d d d d d d d))
    
    ((ld (hl) r) (4 3)
     (0 1 1 1 0 r r r))
    
    ((ld (+ ix d) r) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 1 1 1 0 r r r)
     (d d d d d d d d))
    
    ((ld (+ iy d) r) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 1 1 1 0 r r r)
     (d d d d d d d d))
    
    ((ld (hl) n) (4 3 3)
     (0 0 1 1 0 1 1 0) ;; 36
     (n n n n n n n n))
    
    ((ld (+ ix d) n) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 1 0 1 1 0) ;; 36
     (d d d d d d d d)
     (n n n n n n n n))
    
    ((ld (+ iy d) n) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 1 0 1 1 0) ;; 36
     (d d d d d d d d)
     (n n n n n n n n))
    
    ((ld a (bc)) (4 3)
     (0 0 0 0 1 0 1 0)) ;; 0A
    
    ((ld a (de)) (4 3)
     (0 0 0 1 1 0 1 0)) ;; 1A
    
    ((ld a (nn)) (4 3 3 3)
     (0 0 1 1 1 0 1 0) ;; 3A
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld (bc) a) (4 3)
     (0 0 0 0 0 0 1 0)) ;; 02
    
    ((ld (de) a) (4 3)
     (0 0 0 1 0 0 1 0)) ;; 12
    
    ((ld (nn) a) (4 3 3 3)
     (0 0 1 1 0 0 1 0) ;; 32
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld a ir) (4 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 1 0 1 1 1)) ;; 57
    
    ((ld a rr-) (4 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 1 1 1 1 1)) ;; 5F
    
    ((ld ir a) (4 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 0 1 1 1)) ;; 47
    
    ((ld rr- a) (4 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 1 1 1 1)) ;; 4F
    
    ))

(define 16-bit-load-instructions
  '(((ld dd nn) (4 3 3)
     (0 0 dd dd 0 0 0 1)
     (n n n  n  n n n n)
     (n n n  n  n n n n))
    
    ((ld ix nn) (4 4 3 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 0 0 0 0 1) ;; 21
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld iy nn) (4 4 3 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 0 0 0 0 1) ;; 21
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld hl (nn)) (4 3 3 3 3)
     (0 0 1 0 1 0 1 0) ;; 2A
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld dd (nn)) (4 4 3 3 3 3)
     (1 1 1  0  1 1 0 1) ;; ED
     (0 1 dd dd 1 0 1 1)
     (n n n  n  n n n n)
     (n n n  n  n n n n))
    
    ((ld ix (nn)) (4 4 3 3 3 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 0 1 0 1 0) ;; 2A
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld iy (nn)) (4 4 3 3 3 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 0 1 0 1 0) ;; 2A
     (n n n n n n n n)
     (n n n n n n n n))
     
    ((ld (nn) hl) (4 3 3 3 3)
     (0 0 1 0 0 0 1 0) ;; 22
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld (nn) dd) (4 4 3 3 3 3)
     (1 1 1  0  1 1 0 1) ;; ED
     (0 1 dd dd 0 0 1 1)
     (n n n  n  n n n n)
     (n n n  n  n n n n))
    
    ((ld (nn) ix) (4 4 3 3 3 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 0 0 0 1 0) ;; 22
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld (nn) iy) (4 4 3 3 3 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 0 0 0 1 0) ;; 22
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((ld sp hl) (6)
     (1 1 1 1 1 0 0 1)) ;; F9
    
    ((ld sp ix) (4 6)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 1 1 1 0 0 1)) ;; F9
    
    ((ld sp iy) (4 6)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 1 1 1 0 0 1)) ;; F9
    
    ((push qq) (5 3 3)
     (1 1 qq qq 0 1 0 1))
    
    ((push ix) (4 5 3 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 1 0 0 1 0 1)) ;; E5
    
    ((push iy) (4 5 3 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 1 0 0 1 0 1)) ;; E5
    
    ((pop qq) (4 3 3)
     (1 1 qq qq 0 0 0 1))
    
    ((pop ix) (4 4 3 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 1 0 0 0 0 1)) ;; E1
    
    ((pop iy) (4 4 3 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 1 0 0 0 0 1)) ;; E1
    
    ))

(define exchange-block-transfer-search-instructions
  '(((ex de hl) (4)
     (1 1 1 0 1 0 1 1)) ;; EB
    
    ((ex af af-) (4)
     (0 0 0 0 1 0 0 0)) ;; 08
    
    ((exx) (4)
     (1 1 0 1 1 0 0 1)) ;; D9 [error in docs]
    
    ((ex (sp) hl) (4 3 4 3 5)
     (1 1 1 0 0 0 1 1)) ;; E3
    
    ((ex (sp) ix) (4 4 3 4 3 5)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 1 0 0 0 1 1)) ;; E3
    
    ((ex (sp) iy) (4 4 3 4 3 5)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 1 0 0 0 1 1)) ;; E3
    
    ((ldi) (4 4 3 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 0 0 0 0)) ;; A0
    
    ((ldir) ((4 4 3 5 5)
	     (4 4 3 5))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 0 0 0 0)) ;; B0
    
    ((ldd) (4 4 3 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 1 0 0 0)) ;; A8
    
    ((lddr) ((4 4 3 5 5)
	     (4 4 3 5))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 1 0 0 0)) ;; B8
    
    ((cpi) (4 4 3 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 0 0 0 1)) ;; A1 [error in docs]
    
    ((cpir) ((4 4 3 5 5)
	     (4 4 3 5))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 0 0 0 1)) ;; B1
    
    ((cpd) (4 4 3 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 1 0 0 1)) ;; A9
    
    ((cpdr) ((4 4 3 5 5)
	     (4 4 3 5))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 1 0 0 1)))) ;; B9

(define 8-bit-arithmetic-instructions
  '(((add r) (4)
     (1 0 0 0 0 r r r))
    ((add n) (4 3)
     (1 1 0 0 0 1 1 0) ;; C6
     (n n n n n n n n))
    ((add (hl)) (4 3)
     (1 0 0 0 0 1 1 0)) ;; 86
    ((add (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 0 0 0 1 1 0) ;; 86
     (d d d d d d d d))
    ((add (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 0 0 0 1 1 0) ;; 86
     (d d d d d d d d))
    
    ((adc r) (4)
     (1 0 0 0 1 r r r))
    ((adc n) (4 3)
     (1 1 0 0 1 1 1 0) ;; CE
     (n n n n n n n n))
    ((adc (hl)) (4 3)
     (1 0 0 0 1 1 1 0)) ;; 8E
    ((adc (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD [error in docs]
     (1 0 0 0 1 1 1 0)
     (d d d d d d d d)) ;; 8E
    ((adc (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD [error in docs]
     (1 0 0 0 1 1 1 0)
     (d d d d d d d d)) ;; 8E
    
    ((sub r) (4)
     (1 0 0 1 0 r r r))
    ((sub n) (4 3)
     (1 1 0 1 0 1 1 0)
     (n n n n n n n n)) ;; D6
    ((sub (hl)) (4 3)
     (1 0 0 1 0 1 1 0)) ;; 96
    ((sub (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 0 1 0 1 1 0) ;; 96
     (d d d d d d d d))
    ((sub (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 0 1 0 1 1 0) ;; 96
     (d d d d d d d d))
    
    ((sbc r) (4)
     (1 0 0 1 1 r r r))
    ((sbc n) (4 3)
     (1 1 0 1 1 1 1 0) ;; DE
     (n n n n n n n n))
    ((sbc (hl)) (4 3)
     (1 0 0 1 1 1 1 0)) ;; 9E
    ((sbc (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 0 1 1 1 1 0) ;; 9E
     (d d d d d d d d))
    ((sbc (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 0 1 1 1 1 0) ;; 9E
     (d d d d d d d d))
    
    ((and r) (4)
     (1 0 1 0 0 r r r))
    ((and n) (4 3)
     (1 1 1 0 0 1 1 0) ;; E6
     (n n n n n n n n))
    ((and (hl)) (4 3)
     (1 0 1 0 0 1 1 0)) ;; A6
    ((and (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 1 0 0 1 1 0) ;; A6
     (d d d d d d d d))
    ((and (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 1 0 0 1 1 0) ;; A6
     (d d d d d d d d))
    
    ((or r) (4)
     (1 0 1 1 0 r r r))
    ((or n) (4 3)
     (1 1 1 1 0 1 1 0) ;; F6
     (n n n n n n n n))
    ((or (hl)) (4 3)
     (1 0 1 1 0 1 1 0)) ;; B6
    ((or (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 1 1 0 1 1 0) ;; B6
     (d d d d d d d d))
    ((or (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 1 1 0 1 1 0) ;; B6
     (d d d d d d d d))
    
    ;; these were wrong in the book
    ;; used the undocumented z80 documented pg30 to correct
    ((xor r) (4)
     (1 0 1 0 1 r r r))
    ((xor n) (4 3)
     (1 1 1 0 1 1 1 0) ;; F6
     (n n n n n n n n))
    ((xor (hl)) (4 3)
     (1 0 1 0 1 1 1 0)) ;; B6
    ((xor (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 1 0 1 1 1 0) ;; B6
     (d d d d d d d d))
    ((xor (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 1 0 1 1 1 0) ;; B6
     (d d d d d d d d))
    
    ((cp r) (4)
     (1 0 1 1 1 r r r))
    ((cp n) (4 3)
     (1 1 1 1 1 1 1 0) ;; FE
     (n n n n n n n n))
    ((cp (hl)) (4 3)
     (1 0 1 1 1 1 1 0)) ;; BE
    ((cp (+ ix d)) (4 4 3 5 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 0 1 1 1 1 1 0) ;; BE
     (d d d d d d d d))
    ((cp (+ iy d)) (4 4 3 5 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 0 1 1 1 1 1 0) ;; BE
     (d d d d d d d d))
    
    ((inc r) (4)
     (0 0 r r r 1 0 0))
    ((inc (hl)) (4 4 3)
     (0 0 1 1 0 1 0 0)) ;; 34
    ((inc (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 1 0 1 0 0) ;; 34
     (d d d d d d d d))
    ((inc (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 1 0 1 0 0) ;; 34
     (d d d d d d d d))
    
    ((dec r) (4)
     (0 0 r r r 1 0 1))
    ((dec (hl)) (4 4 3)
     (0 0 1 1 0 1 0 1)) ;; 35
    ((dec (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 1 0 1 0 1) ;; 35
     (d d d d d d d d))
    ((dec (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 1 0 1 0 1) ;; 35
     (d d d d d d d d))
    
    ))

(define general-purpose-control-instructions
  '(((daa) (4)
     (0 0 1 0 0 1 1 1)) ;; 27
    
    ((cpl) (4)
     (0 0 1 0 1 1 1 1)) ;; 2F
    
    ((neg) (4 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 0 1 0 0)) ;; 44
    
    ((ccf) (4)
     (0 0 1 1 1 1 1 1)) ;; 3F
    
    ((scf) (4)
     (0 0 1 1 0 1 1 1)) ;; 37
    
    ((nop) (4)
     (0 0 0 0 0 0 0 0)) ;; 00
    
    ((halt) (4)
     (0 1 1 1 0 1 1 0)) ;; 76
    
    ((di) (4)
     (1 1 1 1 0 0 1 1)) ;; F3
    
    ((ei) (4)
     (1 1 1 1 1 0 1 1)) ;; FB
    
    ((im 0) (4 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 0 1 1 0)) ;; 46
    ((im 1) (4 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 1 0 1 1 0)) ;; 56
    ((im 2) (4 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 1 1 1 1 0)) ;; 5E
    
    ))

(define 16-bit-arithmetic-instructions
  '(((add hl dd) (4 4 3)
     (0 0 dd dd 1 0 0 1))
    
    ((adc hl dd) (4 4 4 3)
     (1 1 1  0  1 1 0 1) ;; ED
     (0 1 dd dd 1 0 1 0))
    
    ((sbc hl dd) (4 4 4 3)
     (1 1 1  0  1 1 0 1) ;; ED
     (0 1 dd dd 0 0 1 0))
    
    ((add ix pp) (4 4 4 3)
     (1 1 0  1  1 1 0 1) ;; DD
     (0 0 pp pp 1 0 0 1))
    
    ((add iy rr) (4 4 4 3)
     (1 1 1  1  1 1 0 1) ;; FD
     (0 0 rr rr 1 0 0 1))
    
    ((inc dd) (6)
     (0 0 dd dd 0 0 1 1))
    ((inc ix) (4 6)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 0 0 0 1 1)) ;; 23
    ((inc iy) (4 6)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 0 0 0 1 1)) ;; 23
    
    ((dec dd) (6)
     (0 0 dd dd 1 0 1 1))
    ((dec ix) (4 6)
     (1 1 0 1 1 1 0 1) ;; DD
     (0 0 1 0 1 0 1 1)) ;; 2B
    ((dec iy) (4 6)
     (1 1 1 1 1 1 0 1) ;; FD
     (0 0 1 0 1 0 1 1)) ;; 2B
    
    ))

(define rotate-and-shift-instructions
  '(((rlca) (4)
     (0 0 0 0 0 1 1 1)) ;; 07
    ((rla) (4)
     (0 0 0 1 0 1 1 1)) ;; 17
    ((rrca) (4)
     (0 0 0 0 1 1 1 1)) ;; 0F
    ((rra) (4)
     (0 0 0 1 1 1 1 1)) ;; 1F
    
    ((rlc r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 0 0 r r r))
    ((rlc (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 0 0 1 1 0)) ;; 06
    ((rlc (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 0 0 1 1 0)) ;; 06
    ((rlc (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 0 0 1 1 0)) ;; 06
    
    ((rl r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 1 0 r r r))
    ((rl (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 1 0 1 1 0)) ;; 16
    ((rl (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 1 0 1 1 0)) ;; 16
    ((rl (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 1 0 1 1 0)) ;; 16
    
    ((rrc r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 0 1 r r r))
    ((rrc (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 0 1 1 1 0)) ;; 0E
    ((rrc (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 0 1 1 1 0)) ;; 0E
    ((rrc (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD [error in docs]
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 0 1 1 1 0)) ;; 0E
    
    ((rr r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 1 1 r r r)) ;; [error in docs]
    ((rr (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 0 1 1 1 1 0)) ;; 1E [error in docs]
    ((rr (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 1 1 1 1 0)) ;; 1E
    ((rr (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 0 1 1 1 1 0)) ;; 1E
    
    ((sla r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 1 0 0 r r r))
    ((sla (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 1 0 0 1 1 0)) ;; 26
    ((sla (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 1 0 0 1 1 0)) ;; 26
    ((sla (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 1 0 0 1 1 0)) ;; 26
    
    ((sra r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 1 0 1 r r r)) ;; [guess due to doc clash]
    ((sra (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 1 0 1 1 1 0)) ;; 2E
    ((sra (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 1 0 1 1 1 0)) ;; 2E
    ((sra (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 1 0 1 1 1 0)) ;; 2E

    ((srl r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 1 1 1 r r r)) ;; [guess due to doc clash]
    ((srl (hl)) (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 0 1 1 1 1 1 0)) ;; 3E
    ((srl (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 1 1 1 1 1 0)) ;; 3E
    ((srl (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 0 1 1 1 1 1 0)) ;; 3E
    
    ((rld) (4 4 3 4 3)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 1 0 1 1 1 1)) ;; 6F
    ((rrd) (4 4 3 4 3)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 1 0 0 1 1 1)) ;; 67
    
    ))

(define set-reset-test-instructions
  '(((bit bb r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (0 1 bb bb bb r r r))
    ((bit bb (hl)) (4 4 4) ;; 12 (4 4 4) 4 in docs, last 4 a typo?
     (1 1 0 0 1 0 1 1) ;; CB
     (0 1 bb bb bb 1 1 0))
    ((bit bb (+ ix d)) (4 4 3 5 4)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 1 bb bb bb 1 1 0))
    ((bit bb (+ iy d)) (4 4 3 5 4)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (0 1 bb bb bb 1 1 0))
    
    ((set bb r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (1 1 bb bb bb r r r))
    ((set bb (hl)) (4 4 4 3) ;; 12 (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (1 1 bb bb bb 1 1 0))
    ((set bb (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (1 1 bb bb bb 1 1 0)) ;; [missing from docs!]
    ((set bb (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (1 1 bb bb bb 1 1 0))
    
    ((res bb r) (4 4)
     (1 1 0 0 1 0 1 1) ;; CB
     (1 0 bb bb bb r r r))
    ((res bb (hl)) (4 4 4 3) ;; 12 (4 4 4 3)
     (1 1 0 0 1 0 1 1) ;; CB
     (1 0 bb bb bb 1 1 0))
    ((res bb (+ ix d)) (4 4 3 5 4 3)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (1 0 bb bb bb 1 1 0)) ;; [missing from docs!]
    ((res bb (+ iy d)) (4 4 3 5 4 3)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 0 0 1 0 1 1) ;; CB
     (d d d d d d d d)
     (1 0 bb bb bb 1 1 0))
     
    ))

(define jump-instructions
  '(((jp nn) (4 3 3)
     (1 1 0 0 0 0 1 1) ;; C3
     (n n n n n n n n)
     (n n n n n n n n))
    
    ((jp cc nn) (4 3 3)
     (1 1 cc cc cc 0 1 0)
     (n n n  n  n  n n n)
     (n n n  n  n  n n n))
    
    ((jr ee) (4 3 5)
     (0 0 0 1 1 0 0 0) ;; 18
     (e e e e e e e e))
    ((jr c ee) ((4 3 5)
		(4 3))
     (0 0 1 1 1 0 0 0) ;; 38
     (e e e e e e e e))
    ((jr nc ee) ((4 3 5)7
		 (4 3))
     (0 0 1 1 0 0 0 0) ;; 30
     (e e e e e e e e))
    ((jr z ee) ((4 3 5)
		(4 3))
     (0 0 1 0 1 0 0 0) ;; 28
     (e e e e e e e e))
    ((jr nz ee) ((4 3 5)
		 (4 3))
     (0 0 1 0 0 0 0 0) ;; 20
     (e e e e e e e e))
    
    ((jp (hl)) (4)
     (1 1 1 0 1 0 0 1)) ;; E9
    ((jp (ix)) (4 4)
     (1 1 0 1 1 1 0 1) ;; DD
     (1 1 1 0 1 0 0 1)) ;; E9
    ((jp (iy)) (4 4)
     (1 1 1 1 1 1 0 1) ;; FD
     (1 1 1 0 1 0 0 1)) ;; E9
    
    ((djnz ee) ((5 3 5)
		(5 3))
     (0 0 0 1 0 0 0 0) ;; 20
     (e e e e e e e e))
    ))

(define call-and-return-instructions
  '(((call nn) (4 3 4 3 3)
     (1 1 0 0 1 1 0 1) ;; CD
     (n n n n n n n n)
     (n n n n n n n n))
    ((call cc nn) ((4 3 4 3 3)
		   (4 3 3))
     (1 1 cc cc cc 1 0 0)
     (n n n  n  n  n n n)
     (n n n  n  n  n n n))
    
    ((ret) (4 3 3)
     (1 1 0 0 1 0 0 1)) ;; C9
    ((ret cc) ((5 3 3)
	       (5))
     (1 1 cc cc cc 0 0 0))
    ((reti) (4 4 3 3)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 1 1 0 1)) ;; 4D
    ((retn) (4 4 3 3)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 0 1 0 1)) ;; 45
    
    ((rst tt) (5 3 3)
     (1 1 tt tt tt 1 1 1))
    ))

(define input-output-instructions
  '(((in a (n)) (4 3 4)
     (1 1 0 1 1 0 1 1) ;; DB
     (n n n n n n n n))
    ((in r (c)) (4 4 4)
     (1 1 1 0 1 1 0 1) ;; ED [error in book]
     (0 1 r r r 0 0 0))
    ((ini) (4 5 3 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 0 0 1 0)) ;; A2
    ((inir) ((4 5 3 4 5)
	     (4 5 3 4))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 0 0 1 0)) ;; B2
    ((ind) (4 5 3 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 1 0 1 0)) ;; AA
    ((indr) ((4 5 3 4 5)
	     (4 5 3 4))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 1 0 1 0)) ;; BA

    ((out (n) a) (4 3 4)
     (1 1 0 1 0 0 1 1) ;; D3
     (n n n n n n n n))
    ((out (c) r) (4 4 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 r r r 0 0 1))
    ((outi) (4 5 3 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 0 0 1 1)) ;; A3
    ((otir) ((4 5 3 4 5)
	     (4 5 3 4))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 0 0 1 1)) ;; B3
    ((outd) (4 5 3 4)
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 0 1 0 1 1)) ;; AB
    ((otdr) ((4 5 3 4 5)
	     (4 5 3 4))
     (1 1 1 0 1 1 0 1) ;; ED
     (1 0 1 1 1 0 1 1)))) ;; BB
