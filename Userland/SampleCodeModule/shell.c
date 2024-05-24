#include <shell.h>
#include <stdint.h>
//#include <libc.h>
#include <commands.h>

//char * commands[AMOUNT_OF_COMMANDS] = {"man", "time", "registers", "snake", "div0", "invalid op", "clear", "zoom in", "zoom out", "set theme", "Esto es Boca"};
char * commands[AMOUNT_OF_COMMANDS] = {"zoomIn", "zoomOut", "clear", "div0", "help"};
void (* commandsReferences[])() = {zoomIn, zoomOut, clear, div0, help};

void initialize_shell(char *command) {
    if(*command == 0){
        call_sys_enter();
        return;
    }
    int id = interpretCommand(command);
    char flag = 0;
    executeCommand(id, &flag, command);

    // if(flag == 0) {
    //     printf("Error: command not found\n");
    // }
}

int interpretCommand(char * command) {
    int index = -1;
    for (int i = 0; i < AMOUNT_OF_COMMANDS; i++) {
        if (strcmp(command, commands[i]) == 0) {
            return i;
        }
    }
    return index;
}

void executeCommand(int indexCommand, char * flag, char * command) {
    if (indexCommand == -1 ) {
        call_sys_drawError(command);
        *flag = 0;
        return;
    }
    call_sys_commandEnter();
    commandsReferences[indexCommand]();
    call_sys_enter();
    *flag = 1;
}







