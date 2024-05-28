#include <shell.h>
#include <stdint.h>
#include <commands.h>

char * commands[AMOUNT_OF_COMMANDS] = {"zoomIn", "zoomOut", "clear", "div0", "help", "registers", "date", "eliminator"};
void (* commandsReferences[])() = {zoomIn, zoomOut, clear, div0, help, registers, date, eliminator};

void initialize_shell(char *command) {
    if(*command == 0){
        call_sys_enter();
        return;
    }
    int id = interpretCommand(command);
    char flag = 0;
    executeCommand(id, &flag, command);
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







