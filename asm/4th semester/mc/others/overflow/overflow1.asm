        AREA OVERFLOW,CODE,READONLY
ENTRY
        LDR R1,=0x92B17600
        LDR R2,=0x859237A4
        ADCS R3,R1,R2
STOP    B STOP
        END