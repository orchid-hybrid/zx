;; TODO make a test .asm file with all 8-bit-load-instructions

;; r and r2 index into register-table
;; n is an 8 bit integer
;; d is a two's complement displacement integer
;; nn is a 16 bit integer
;; a is the accumulator register
;; ir is the interrupt register
;; rr is the refresh register

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

