#include <keyboardDriver.h>
#include <videoDriver.h>

static char shiftPressed = 0;

char keyMap[][2] = { 
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

// map the key to the corresponding character checking shift
uint8_t getKeyMapping(uint64_t number) {
    if(number == LEFT_SHIFT_NBR  || number == RIGHT_SHIFT_NBR ){
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

// function that handles the keyboard
void keyboard_handler(){
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
    char letter = getKeyMapping(key);
    
    buffer[buffer_pos] = letter;
    
    if(letter == ','){
        flag_screenShot = 1;
        saveState();
    }
    return;
}

// function that reads the characters
void readChar(uint8_t * buf, uint32_t count, uint32_t * size){
    char * buffer = getAddress();
    int write_pos = getPos(); // get writing position
    int read_pos = getReadPos(); // get reading position
    int i = 0;
    while(count !=0  && read_pos != write_pos){
        buf[i] = buffer[read_pos];
        read_pos = (read_pos + 1) % SIZE;
        i++;
    }
    *size = i;
    setReadPos(read_pos); // update reading position
}






