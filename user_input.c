#include "shell.h"

/**
 * read_command - A program that reads the commands
 * @command: command line program
 * @size: string
 * Return: Always 0
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shell_print("Error while reading input.\n");
					exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
