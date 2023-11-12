#include "shell.h"
/**
 * exit_builtin - for which the compiler generates inline code at compile time.
 * @message: is pointer that points to a char.
 * Return: it returns 1 or 0.
 */
int exit_builtin(char *message)
{
	char *builtin[] = {"exit", "envrmt", NULL};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(message, builtin[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_b - it handles built-in functiuon.
 * @command: double pointer to a char.
 * @argv: a pointer to an array
 * @status: is a pinter to an integer.
 * @index: an integer.
 */
void handle_b(char **command, char **argv, int *status, int index)
{
	(void) argv;
	(void) index;

	if (_strcmp(command[0], "exit") == 0)
		exit_sh(command, status);
	else if (_strcmp(command[0], "envrmt") == 0)
		p_envrmt(command, status);
}
/**
 * exit_sh - this function called when we want to exit the shell.
 * @command: is a double pointer points to a char.
 * @status: is a pointer to an integer.
 */
void exit_sh(char **command, int *status)
{
	freearray(command);
	exit(*status);
}
/**
 * p_envrmt - this function prints the environ.
 * @command: is a double pointer to a char.
 * @status: is a pointer to an integer.
 */
void p_envrmt(char **command, int *status)
{
	int i;

	for (i = 0; envrmt[i]; i++)
	{
		write(STDOUT_FILENO, envrmt[i], _strlen(envrmt[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(command);
	(*status) = 0;
}
