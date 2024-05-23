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