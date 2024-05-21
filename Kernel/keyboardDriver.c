#include <keyboardDriver.h>
#include <buf_kb.h>
#include <lib.h>
#include <videoDriver.h>



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
        {'\b', 128},
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
        {167, '~'},
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



void keyboard_handler(){
    uint64_t key = get_key();
    // if(key == 0){
    //   return;
    // }
    
    char * buffer = getAddress();
    int buffer_pos = getPos();

    // Verificamos si hay lugar en el buffer, si no volvemos al inicio
    if(getKeyMapping(key) == '\b'){
        ncBackspace(buffer_pos);
    }else if(buffer_pos+1 < SIZE ){
        newPos(buffer_pos+1);
        buffer[buffer_pos+1]=0;
    }else{
        newPos(0);
        buffer[0]=0;
    }
    // ya pasados los chekeos, almaceno la key
    char letter = getKeyMapping(key);
    kb_handler(key,letter);
    buffer[buffer_pos] = letter;
    
    //drawLine(letter);
    return;
}

void ncBackspace(int buffer_pos){
    if(buffer_pos==0){
        deleteBuffAt(buffer_pos);
        newPos(SIZE);
        buffer_pos = SIZE;
        delete();
        return;
    }
    deleteBuffAt(buffer_pos);
    buffer_pos--;
    newPos(buffer_pos);
    delete();
    return;
}

void kb_handler(uint64_t key, char letter){
    int buffer_pos = getPos();
    if(key == 0x39){
        drawLine(' ');
        return;
    }
    if(letter == '\n'){
        enter();
        return;
    }
    if(letter == '\t'){
        for(int i = 0;i<4;i++){
            drawLine(' ');
        }
        return;
    }
    if(key >= 0 && key < 256 && getKeyMapping(key) != 0 && letter != '\b'){
        drawLine(letter);
        return;
    }
    return;
}


