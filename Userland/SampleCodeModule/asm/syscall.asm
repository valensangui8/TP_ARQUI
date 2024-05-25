section .text
GLOBAL call_sys_drawWord
GLOBAL call_sys_read
GLOBAL call_sys_drawChar
GLOBAL call_sys_enter
GLOBAL call_sys_delete
GLOBAL call_sys_drawError
GLOBAL call_sys_commandEnter
GLOBAL call_sys_zoomIn
GLOBAL call_sys_zoomOut
GLOBAL call_sys_get_hour
GLOBAL call_sys_get_minute
GLOBAL call_sys_clear
GLOBAL call_sys_getScale
GLOBAL call_sys_drawWithColor
GLOBAL call_sys_drawRegisters
call_sys_read:
    mov rax, 0
    int 80h
    ret
call_sys_drawWord:
    mov rax, 1
    int 80h
    ret

call_sys_drawChar:
    mov rax, 2
    int 80h
    ret

call_sys_enter:
    mov rax, 3
    int 80h
    ret

call_sys_delete:
    mov rax, 4
    int 80h
    ret

call_sys_drawError:
    mov rax, 5
    int 80h
    ret

call_sys_commandEnter:
    mov rax, 6
    int 80h
    ret

call_sys_zoomIn:
    mov rax, 7
    int 80h
    ret

call_sys_zoomOut:
    mov rax, 8
    int 80h
    ret

call_sys_clear:
    mov rax, 9
    int 80h
    ret

call_sys_getScale:
    mov rax, 10
    int 80h
    ret

call_sys_drawWithColor:
    mov rax, 11
    int 80h
    ret

call_sys_drawRegisters:
    mov rax, 12
    int 80h
    ret

call_sys_get_hour:
.wait:
    mov al, 0x0A
    out 0x70, al
    in al, 0x71
    test al, 0x80
    jnz .wait

    mov al, 4
    out 70h, al
    in al, 71h

    sti
    ret

call_sys_get_minute:
    cli
.wait:
    mov al, 0x0A
    out 0x70, al
    in al, 0x71
    test al, 0x80
    jnz .wait

    mov al, 2
    out 70h, al
    in al, 71h

    sti
    ret
