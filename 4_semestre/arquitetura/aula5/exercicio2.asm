
MOV  30h, #2h
MOV  31h, #2h
MOV  32h, #1h
MOV  33h, #1h
MOV  34h, #9h
MOV  35h, #0h
MOV  36h, #7h
MOV  37h, #8h
MOV  38h, #8h

READ:
	MOV R0, #30h
	MOV R1, #9h

ROT2:
	MOV A, @R0
	ACALL CHECK
	INC R0
	DJNZ R1, ROT2
	SJMP $

CHECK:
	CLR C
	MOV R6, A
	SUBB A, 39h
	JNC SUBSTITUTE
	RET

SUBSTITUTE:
	MOV 39h, R6
	RET
