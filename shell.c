#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */

int main(void)
{
	char command[128];

	while (true)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}

	return (0);
}
