#include <syscalls.h>
#include <stdint.h>
#include <myStdio.h>

//hacer funciones en c para trabajar en los main




char getChar(){
    uint8_t c;
    uint32_t size = 0;
    while(size == 0){
        call_sys_read(&c,1,&size);
    }
    return c;
}

int strcmp(const char * s1, const char * s2) {
    int i = 0;
    while(s1[i] != 0  && s2[i] != 0){
        if(s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i]-s2[i];
}