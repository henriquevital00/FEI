DELAY:
MOV R0, #82
MOV R2, #21

ROT1:
MOV R1, #47

ROT2:
DJNZ R1, ROT2
DJNZ R0, ROT1

ROT3:
DJNZ R2, ROT3
RET