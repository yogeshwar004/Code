        AREA ADDITION,CODE,READONLY
ENTRY
        MOV R1,#0x5
        MOV R2,#0x4
        ADD R3,R1,R2
        SUB R4,R1,R2
        MUL R5,R1,R2
XS      B XS
        END