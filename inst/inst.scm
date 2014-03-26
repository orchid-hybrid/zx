;; TODO make a test .asm file with all 8-bit-load-instructions

;; r and r2 index into register-table
;; n is an 8 bit integer
;; d is a two's complement displacement integer
;; nn is a 16 bit integer
;; a is the accumulator register
;; ir is the interrupt register
;; rr is the refresh register
;; af- is used for af' (in general suffix with -)

;; pg81
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
    
    ((ld a rr) (4 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 1 1 1 1 1)) ;; 5F
    
    ((ld ir a) (4 5)
     (1 1 1 0 1 1 0 1) ;; ED
     (0 1 0 0 0 1 1 1)) ;; 47
    
    ((ld rr a) (4 5)
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
    
    ;; ????
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
    ))
