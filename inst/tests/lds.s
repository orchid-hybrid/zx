.SECTION "MAIN"
	LD	A,H
	LD	A,H
	LD	A,H
	LD	E,L
	LD	E,L
	LD	A,H
	LD	E,L
	LD	A,$27
	LD	B,$44
	LD	C,$F0
	LD	D,$EF
	LD	E,$68
	LD	H,$94
	LD	L,$01
	LD	E,(HL)
	LD	C,(IX-7)
	LD	E,(IX-3)
	LD	D,(IX+0)
	LD	H,(IX+7)
	LD	L,(IX+9)
	LD	A,(IY-121)
	LD	(IX-77),B
	LD	(IX-33),B
	LD	(IX+0),C
	LD	(IX+0),$CC
	LD	(IX-77),$BB
	LD	(IX-33),$BB
	LD	(IX+99),C
	LD	(IY-121),H
	LD	(HL),E
	LD	(HL),C
	LD	(HL),$48
	LD	(HL),$35
	LD	A,(BC)
	LD	A,(DE)
	LD	(BC),A
	LD	(DE),A
	LD	A,($2D55)
	LD	A,($4FFF)
	LD	A,($8E23)
	LD	($923F),A
	LD	($B015),A
	LD	($CD82),A
	LD	A,I
	LD	A,R
	LD	I,A
	LD	R,A
.ENDS

