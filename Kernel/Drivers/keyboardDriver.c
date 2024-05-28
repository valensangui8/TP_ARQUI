#include <keyboardDriver.h>
#include <buf_kb.h>
#include <lib.h>
#include <videoDriver.h>
#include <register.h>
#include <interrupts.h>



static char shiftPressed = 0;
static char capsLockPressed = 0;



char keyMap[][2] = { // [cantidad de teclas][2]
                      // primer elemento es la tecla que presionas y el segundo es la tecla sumada con shift
        {0, 0},
        {0, 0}, // esc key 
        {'1', '!'},
        {'2', '@'},
        {'3', '#'},
        {'4', '$'},
        {'5', '%'},
        {'6', '^'},
        {'7', '&'},
        {'8', '*'},
        {'9', '('},
        {'0', ')'},
        {'-', '_'},
        {'-', '+'},
        {'\b', '\b'},
        {'\t', '\t'},
        {'q', 'Q'},
        {'w', 'W'},
        {'e', 'E'},
        {'r', 'R'},
        {'t', 'T'},
        {'y', 'Y'},
        {'u', 'U'},
        {'i', 'I'},
        {'o', 'O'},
        {'p', 'P'},
        {'[', '{'},
        {']', '}'},
        {'\n', '\n'},
        {0, 0},
        {'a', 'A'},
        {'s', 'S'},
        {'d', 'D'},
        {'f', 'F'},
        {'g', 'G'},
        {'h', 'H'},
        {'j', 'J'},
        {'k', 'K'},
        {'l', 'L'},
        {';', ':'},
        {'\'', '\"'},
        {'`','~'},
        {0, 0}, // left shift 
        {'\\', '|'},
        {'z', 'Z'},
        {'x', 'X'},
        {'c', 'C'},
        {'v', 'V'},
        {'b', 'B'},
        {'n', 'N'},
        {'m', 'M'},
        {',', '<'},
        {'.', '>'},
        {'/', '?'},
        {0, 0}, // right shift
        {0, 0}, //(keypad) * pressed
        {0, 0}, //left alt pressed
        {' ', ' '} // space 
    };

uint8_t getKeyMapping(uint64_t number) {
    if(number == LEFT_SHIFT_NBR  || number == RIGHT_SHIFT_NBR){
        shiftPressed = 1;
    }

    if(number == LEFT_SHIFT_RELEASED || number == RIGHT_SHIFT_RELEASED){
        shiftPressed = 0;
    }

    if(number >= RELEASED){
        return 0;
    }

    if(shiftPressed){
        return keyMap[number][1];
    }
    return keyMap[number][0];
}

void keyboard_handler(uint64_t * registers){
    uint64_t key = get_key();
    char * buffer = getAddress();
    int buffer_pos = getPos();
    if(key < 0 || key > 256 || getKeyMapping(key) == 0){
        return;
    }
    if(buffer_pos+1 < SIZE ){
        newPos(buffer_pos+1);
        buffer[buffer_pos+1]=0;
    }else{
        newPos(0);
        buffer[0]=0;
    }
    // ya pasados los chekeos, almaceno la key
    char letter = getKeyMapping(key);
    
    buffer[buffer_pos] = letter;
    
    if(letter == ','){
        flag_screenShot = 1;
        saveState();
    }
    return;
}

void ncBackspace(){
    int buffer_pos = getPos();
    if(buffer_pos==0){
        deleteBuffAt(buffer_pos);
        buffer_pos = newPos(SIZE);
    } else {
        deleteBuffAt(buffer_pos);
        buffer_pos--;
        buffer_pos = newPos(buffer_pos);
    }
    delete(); // Llama a la función delete
    return;
}

void readChar(uint8_t * buf, uint32_t count, uint32_t * size){
    char * buffer = getAddress();
    int write_pos = getPos(); // Posición de escritura
    int read_pos = getReadPos(); // Posición de lectura
    int i = 0;
    while(count !=0  && read_pos != write_pos){
        buf[i] = buffer[read_pos];
        read_pos = (read_pos + 1) % SIZE; // Asume que SIZE es el tamaño del buffer
        i++;
    }
    *size = i;
    setReadPos(read_pos); // Actualiza la posición de lectura
}






