        AREA PRG1,CODE,READONLY
ENTRY
        MOV R1,#0x6400
        MOV R2,#0x3200
        ADD R0,R1,R2
XS      B XS
        END