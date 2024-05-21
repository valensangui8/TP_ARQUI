#include "buf_kb.h"
static struct buff_kb buffer = {0,0,{0}};
static buff pointer = &buffer;

int getPos(){
    return pointer->pos;
}
int newPos(int newPos){
    pointer->pos= newPos;
    return newPos;
}
char * getAddress(){
    return pointer->buffer;
}
char getCharAt(int pos){
    return pointer->buffer[pos];
}
void deleteBuffAt(int pos){
    pointer->buffer[pos]=0;
}
