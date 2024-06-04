GLOBAL cpuVendor
GLOBAL get_key
GLOBAL outb
GLOBAL inb

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

get_key:
	push rbp
	mov rbp,rsp
	mov rax,0
	in al,0x60
	mov rsp,rbp
	pop rbp
	ret

inb:                ; Funciones para el correcto funcionamiento del soundDriver
    push rbp
    mov rbp, rsp

    mov rdx,rdi
    in al,dx        ; pasaje en 8 bits

    mov rsp, rbp
    pop rbp
    ret

outb:
    push rbp
    mov rbp, rsp

    mov rax, rsi
    mov rdx, rdi
    out dx, al        ; pasaje en 8 bits

    mov rsp, rbp
    pop rbp
    ret

section .data
timeval:
	tv_sec dd 0
	tv_usec dd 0