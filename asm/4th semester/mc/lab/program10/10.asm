 AREA INTERRUPT,CODE,READONLY
ENTRY
    MRS R1,CPSR
    BIC R1,R1,#0x80
    MSR CPSR_C,R1
XSS B XSS
    END