#include "shell.h"

/**
 * executeCommand - Execute a command with arguments using execve
 * @args: Array of strings representing the command and its arguments
 *
 */


void executeCommand(char **args)
{
	execve(args[0], args, NULL);

	perror(args[0]);
	exit(EXIT_FAILURE);
}


/**
 * executeChildProcess - Execute the command in a child process
 * @args: Arrays of strings representing the command and its arguments
 */

void executeChildProcess(char **args)
{
	executeCommand(args);
}

/**
 * waitForChildProcess - wait for the child process to complete
 * @pid: PID of the child process
 */

void waitForChildProcess(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
}

/**
 * displayPrompt - Display the shell prompt
 */

void displayPrompt(void)
{
	write(STDOUT_FILENO, "$) ", 4);
}


/**
 * runShell - Run the simple shell
 *
 */

void runShell(void)
{
	char input[MAX_INPUT_LENGTH]

	while (1)
	{
		displayPrompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		char *args[MAX_INPUT_LENGTH];

		tokenizeInput(input, args);

		if (args[0] != NULL)
		{
			pid_t pid;

			pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (pid == 0)
			{
				executeChildProcess(args);
			}
			else
			{

				waitForChildProcess(pid);
			}
		}
	}

}
