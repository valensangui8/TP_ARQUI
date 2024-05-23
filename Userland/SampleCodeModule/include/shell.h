#ifndef SHELL_H
#define SHELL_H

#define AMOUNT_OF_COMMANDS 2

// Shell manager
void initialize_shell(char * command);

// Checks if the command is valid
int interpretCommand(char * command);

// Executes the command
void executeCommand(int indexCommand, char * flag,  char * command);

#endif



