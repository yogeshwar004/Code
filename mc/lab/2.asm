        AREA LOGICALOPERATION,CODE,READONLY
ENTRY
        MOV R1,#0x43
        MOV R2,#0xFC
        ORR R3,R1,R2
        AND R4,R1,R2
        EOR R5,R1,R2
XS      B XS
        END