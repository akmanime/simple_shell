#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PATH_LENGTH 4096

typedef struct
{
	char **env;
} argu_t;


void display_prompt(void);
void shell_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);
void executeCommand(char **args);
void tokenizeInput(char *input, char **args);
void executeChildProcess(char **args);
void waitForChildProcess(pid_t pid);
void runShell(void);
void handle_command(char *command);
int shell_exit(argu_t *argu);
int _env(argu_t *argu);
int main(void);


#endif
