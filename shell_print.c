#include "shell.h"

/**
 * shell_print - A program that prints the shell
 * @message: string
 * Return: Always 0
 */

void shell_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
