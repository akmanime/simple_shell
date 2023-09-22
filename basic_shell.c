#include "shell.h"

/**
 * executeCommand - Execute a command using execve
 * @command: The command to execute
 *
 */

void executeCommand(const char *command)
{
	char *args[2];

	args[0] = strdup(command);
	args[1] = NULL;

	execve(args[0], args, NULL);

	perror(args[0]);
	exit(EXIT_FAILURE);
}

/**
 * main - The main function
 *
 * Return: 0
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			executeCommand(input);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}

	exit(EXIT_SUCCESS);
}
