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
	MOV R0, 30h
	MOV R1, 9h
	ROT2:
		MOV A, @R0
		CJNE R0, #2h, LOOP
		MOV P1, A
LOOP:
    INC R0
	DJNZ R1, ROT2
	RET
