        AREA FIBONACCI,CODE,READONLY
ENTRY
        MOV R0,#2
        LDR R1,VALUE
        MOV R2,#0x0
        MOV R3,#0x1
        STR R2,[R1],#4
        STR R3,[R1],#4
LOOP
        ADD R4,R3,R2
        STR R4,[R1],#4
        MOV R2,R3
        MOV R3,R4
        ADD R0,R0,#1
        CMP R0,#0X0A
        BNE LOOP
XSS     B XSS
VALUE DCD 0x40000000
        END