        AREA SUM,CODE,READONLY
ENTRY
START
        MOV R5,#10  ;R5=10
        MOV R0,#0   ;R0=0
        MOV R1,#1   ;R1=1
LOOP    ADD R0,R0,R1    ;R0=R0+R1
        ADD R1,R1,#1    ;R1=R1+1
        SUB R5,R5,#1    ;R5=R5-1
        CMP R5,#0   ;R5==0
        BNE LOOP    ;BRANCHES WHEN THEY ARE UNEQUAL
        LDR R4,=RESULT
        STR R0,[R4]
XSS     B XSS
        AREA DATA2,DATA,READWRITE
RESULT  DCD 0x00000000
        END