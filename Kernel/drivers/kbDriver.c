#include "include/kb_driver.h"

void keyboard_handler(){
    uint16_t key = getKey();
    if(key == NULL){
        return;
    }


}