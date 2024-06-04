#include <commands.h>

void zoomIn(){
    int scale;
    call_sys_getScale(&scale);
    if(scale == 4){
        printf("Max zoom in reached");
    }else{
        call_sys_zoomIn();
    }
}
void zoomOut(){
    int scale;
    call_sys_getScale(&scale);
    if(scale == 1){
        printf("Max zoom out reached");
    }else{
        call_sys_zoomOut();
    }
}

void clear(){
    call_sys_clear();
}

void help(){
    call_sys_commandEnter();
    
    
    printf("GNU bash, version 3.2.57(1)-release (arm64-apple-darwin23)");
    printf("These shell commands are defined internally.  Type `help' to see this list.");
    printf("A star (*) next to a name means that the command is disabled.");
    

    printf("PROGRAMS AVAILABLE FOR USER: ");
    
    
    call_sys_drawWithColor(" help", 0x32a852);
    printf(" - shows the different programs available.");
    

    call_sys_drawWithColor(" date", 0x32a852);
    printf(" - Retrieve the current day and time.");
   
    
    call_sys_drawWithColor(" eliminator", 0x32a852);
    printf(" - Play the Eliminator game, available for both single-player and two-player modes.");
  

    call_sys_drawWithColor(" clear", 0x32a852);
    printf(" - Clear the screen.");
   

    call_sys_drawWithColor(" zoomIn", 0x32a852);
    printf(" - Increase text size. Clears screen after change.");


    call_sys_drawWithColor(" zoomOut", 0x32a852);
    printf(" - Decrease text size. Clears screen after change.");
  

    call_sys_drawWithColor(" registers", 0x32a852);
    printf(" - View the registers in use after pressing ',' .");

    call_sys_drawWithColor(" itba", 0x32a852);
    printf(" - We'll show you ITBA's logo after execution.");
 

    call_sys_drawWithColor(" EXCEPTIONS", 0xc70e24);
    call_sys_commandEnter();

    call_sys_drawWithColor(" invalidOpcode", 0x32a852);
    printf(" - Indicates an invalid operation.");
   

    call_sys_drawWithColor(" div0", 0x32a852);
    printf(" - Signals division by zero.");
    
}

void div0() {
    int a, b, c;
    a = 0;
    b = 1;
    c = b / a;
    a = c;
}

void registers(){
    call_sys_drawRegisters();
}




/*DATE*/

char timeBuffer[5] = {'\0'};
char dayBuffer[8] = {'\0'};

unsigned int decode(unsigned int time){
    return (time >> 4) * 10 + (time & 0x0F);				//Funcion que pasa el tiempo en BCD(binary coded decimal) a un numero en decimal
}
static uint32_t numberToBase(uint64_t value, char * buffer, uint32_t base) {
    char *p = buffer;
    char *p1, *p2;
    uint32_t digits = 0;

    do {
        uint32_t remainder = value % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        digits++;
    } while (value /= base);

    // Terminate string in buffer.
    *p = 0;

    //Reverse string in buffer.
    p1 = buffer;
    p2 = p - 1;
    while (p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }

    return digits;
}
void buildTwoDigitsData(char* buffer, int dataTime) {
    if (dataTime < 10) {
        buffer[0] = '0';
        numberToBase(dataTime, buffer + 1, 10);
    } else {
        numberToBase(dataTime, buffer, 10);
    }
}
char* getTime(){
    int hours = decode(call_sys_get_date(HOURS)) - 3;
    int minutes = decode(call_sys_get_date(MINUTES));

    buildTwoDigitsData(timeBuffer, hours);
    timeBuffer[2] = ':';
    buildTwoDigitsData(timeBuffer + 3, minutes);
    
    return timeBuffer;
}

char * getDay() {
    int day = decode(call_sys_get_date(DAY));
    int month = decode(call_sys_get_date(MONTH));
    int year = decode(call_sys_get_date(YEAR));

    buildTwoDigitsData(dayBuffer, day);
    dayBuffer[2] = '/';
    buildTwoDigitsData(dayBuffer + 3, month);
    dayBuffer[5] = '/';
    buildTwoDigitsData(dayBuffer + 6, year);

    return dayBuffer;
}

void date() {
    call_sys_drawWord("Current day: ");
    call_sys_drawWord(getDay());

    call_sys_commandEnter();

    call_sys_drawWord("Current time: ");
    call_sys_drawWord(getTime());
}