#include <register.h>
#include <videoDriver.h>

registerStructT registros = {0};

int flag_screenShot = 0;
void printRegisters(){
	if (flag_screenShot == 0){
		drawWord("Error - No hay screenshots de registros");
		return;
	}
	drawWord("RIP = 0x");
	drawRegisters(registros.rip);
	drawWord("RAX = 0x");
	drawRegisters(registros.rax);
	drawWord("RBX = 0x");
	drawRegisters(registros.rbx);
	drawWord("RCX = 0x");
	drawRegisters(registros.rcx);
	drawWord("RDX = 0x");
	drawRegisters(registros.rdx);
	drawWord("RSP = 0x");
	drawRegisters(registros.rsp);
	drawWord("RBP = 0x");
	drawRegisters(registros.rbp);
	drawWord("RSI = 0x");
	drawRegisters(registros.rsi);
	drawWord("RDI = 0x");
	drawRegisters(registros.rdi);
	drawWord("R8  = 0x");
	drawRegisters(registros.r8);
	drawWord("R9  = 0x");
	drawRegisters(registros.r9);
	drawWord("R10 = 0x");
	drawRegisters(registros.r10);
	drawWord("R11 = 0x");
	drawRegisters(registros.r11);
	drawWord("R12 = 0x");
	drawRegisters(registros.r12);
	drawWord("R13 = 0x");
	drawRegisters(registros.r13);
	drawWord("R14 = 0x");
	drawRegisters(registros.r14);
	drawWord("R15 = 0x");
	drawRegisters(registros.r15);
	drawWord("ss = 0x");
	drawRegisters(registros.ss);
	drawWord("cs = 0x");
	drawRegisters(registros.cs);
	drawWord("rflags = 0x");
	drawRegisters(registros.rflags);
}

void RegisterCopy(registerStructT * dest, registerStructT * src){
	for(int i = 0 ; i < REGISTERS ; i++){
		((uint64_t *) dest)[i] = ((uint64_t *) src)[i];
	}
}