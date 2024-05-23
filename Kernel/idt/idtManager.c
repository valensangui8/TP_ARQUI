#include <stdint.h>
#include <videoDriver.h>
#include <keyboardDriver.h>

static void sys_Read(uint8_t * buf, uint32_t count, uint32_t * size);
static void sys_DrawWord(char * word);
static void sys_DrawChar(char letter);
static void sys_delete();
static void sys_enter();
static void sys_drawError(char * command);
static void sys_commandEnter();
static void sys_zoomIn();
static void sys_zoomOut();


void idtManager(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t rax){
    switch (rax)
    {
    case 0: // read
        sys_Read((uint8_t *) rdi, (uint32_t) rsi, (uint32_t *) rdx); // rdi = buffer ; rsi = size , rdx = count 
        break;
    case 1: // write
        sys_DrawWord((char *) rdi); // rdi = palabra 
        break;
    case 2:
        sys_DrawChar((char) rdi); // rdi = letra 
        break;
    case 3:
        sys_enter(); 
        break;
    case 4:
        sys_delete(); 
        break;
    case 5:
        sys_drawError((char *) rdi);
        break;
    case 6:
        sys_commandEnter();
        break;
    case 7:
        sys_zoomIn();
        break;
    case 8:
        sys_zoomOut();
        break;
    }
}


void sys_Read(uint8_t * buf, uint32_t count, uint32_t * size){
    readChar(buf, count, size);
}

void sys_DrawWord(char * word){
    drawWord(word);
}

void sys_DrawChar(char letter){
    drawLine(letter);
}

void sys_enter(){
    enter();
}

void sys_delete(){
    delete();
}

void sys_drawError(char * command){
    drawError(command, 1);
}

void sys_commandEnter(){
    commandEnter();
}

void sys_zoomIn(){
    incScale();
}

void sys_zoomOut(){
    decScale();
}