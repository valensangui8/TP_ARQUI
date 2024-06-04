GLOBAL invalidOpcode

section .text

invalidOpcode:
    jmp inval
    ret

section .data 
    inval equ 200