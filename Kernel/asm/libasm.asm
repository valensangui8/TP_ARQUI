GLOBAL cpuVendor
GLOBAL get_key
GLOBAL get_hour
GLOBAL get_minute

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

get_hour:
	mov al, 4
	out 70h, al
	in al, 71h
	ret

get_minute:
	mov al, 2
	out 70h, al
	in al, 71h
	ret
	
