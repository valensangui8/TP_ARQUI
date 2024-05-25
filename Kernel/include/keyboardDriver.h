#ifndef KEYBOARDDRIVER_H
#define KEYBOARDDRIVER_H

#include <stdint.h>
#include <register.h>


#define LEFT_SHIFT_NBR 42
#define RIGHT_SHIFT_NBR 54
#define RELEASED 128
#define LEFT_SHIFT_RELEASED 170
#define RIGHT_SHIFT_RELEASED 182

void keyboard_handler();
extern uint64_t get_key(); //Funcion en ass que obtiene el valor de la tecla
extern void saveRegisters(registerStructT *registers);
void kb_handler(uint64_t key, char letter);
#endif