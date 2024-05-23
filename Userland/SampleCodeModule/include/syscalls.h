
#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

extern void call_sys_drawWord(char *word);
extern void call_sys_read(uint8_t * buf, uint32_t count, uint32_t * size);
extern void call_sys_drawChar(char letter);
extern void call_sys_delete();
extern void call_sys_enter();
extern void call_sys_drawError(char * command);
extern void call_sys_commandEnter();
extern void call_sys_zoomIn();
extern void call_sys_zoomOut();

#endif