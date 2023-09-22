#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/*
 *main - entry point
 *
 * return: 0
 */

int main(void)
{
	size_t len;
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("SimpleShell> ");
		fgets(input, sizeof(input), stdin);

		len = strlen(input);

		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		handle_command(input);
	}

	return (0);
}

/*
 *handle_command - handles and forks if command is called
 *
 */


void handle_command(char *command)
{
	pid_t child_pid;
	int status;
	char *path = getenv("PATH");
	char *token, *saveptr;

	token = strtok_r(path, ":", &saveptr);
	while (token != NULL)
	{
		char full_path[MAX_PATH_LENGTH];

		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
	if (access(full_path, X_OK) == 0)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			char *args[2];

			args[0] = full_path;
			args[1] = NULL;
			execv(full_path, args);
			perror("execv");
			exit(1);
		} else if (child_pid < 0)
		{
			perror("fork");
		} else
		{
			waitpid(child_pid, &status, 0);
		}
		break;
	}
	token = strtok_r(NULL, ":", &saveptr);
	}
	if (token == NULL)
	{
		printf("Command '%s' not found\n", command);
	}
}
