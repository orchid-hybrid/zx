.SECTION "MAIN"
	CALL	$0123
	CALL	$75E3
	CALL	NZ,$2223
	CALL	Z,$3242
	CALL	NC,$C00C
	CALL	C,$CDDC
	CALL	PO,$1347
	CALL	PE,$6688
	CALL	P,$1723
	CALL	M,$4873
	RET
	RET	NZ
	RET	P
	RET	NC
	RETI
	RETN
	RST	$00
	RST	$08
	RST	$10
	RST	$18
	RST	$20
	RST	$28
	RST	$30
	RST	$38
.ENDS
