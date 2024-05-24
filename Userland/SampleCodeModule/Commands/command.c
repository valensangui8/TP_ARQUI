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
    

    call_sys_drawWithColor(" time", 0x32a852);
    printf(" - Retrieve the current time.");
   
    
    call_sys_drawWithColor(" eliminator", 0x32a852);
    printf(" - Play the Eliminator game, available for both single-player and two-player modes. Follow the command with ");
    printf(" the number of players you want to play with.");
  

    call_sys_drawWithColor(" clear", 0x32a852);
    printf(" - Clear the screen.");
   

    call_sys_drawWithColor(" zoomIn", 0x32a852);
    printf(" - Increase text size. Clears screen after change.");


    call_sys_drawWithColor(" zoomOut", 0x32a852);
    printf(" - Decrease text size. Clears screen after change.");
  

    call_sys_drawWithColor(" registers", 0x32a852);
    printf(" - View the registers in use after pressing ',' .");
 

    call_sys_drawWithColor(" EXCEPTIONS", 0xc70e24);
    call_sys_commandEnter();

    call_sys_drawWithColor(" inval op", 0x32a852);
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