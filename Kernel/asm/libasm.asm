GLOBAL cpuVendor
GLOBAL get_key
GLOBAL sleep

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

sleep:
	mov dword [tv_sec], 5
	mov dword [tv_usec], 0
	mov eax, 162
	mov ebx, timeval
	int 80h

	ret

section .data
timeval:
	tv_sec dd 0
	tv_usec dd 0