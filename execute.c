#include "shell.h"
/**
 * _execute - function that execute a command with arguments.
 * @argv: An array of strings.
 * @command: a double pointer to a char.
 * @index: is an integer.
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **argv, int index)
{
	char *msg;
	pid_t ch;
	int status;

	msg = get_path(command[0]);
	if (!msg)
	{
		PrintError(argv[0], command[0], index);
		freearray(command);
		return (127);
	}
	ch = fork();
	if (ch == 0)
	{
		if (execve(msg, command, envrmt) == -1)
		{
			free(msg);
			msg = NULL;
			freearray(command);
		}
	}
	else
	{
		waitpid(ch, &status, 0);
		freearray(command);
		free(msg);
		msg = NULL;
	}
	return (WEXITSTATUS(status));
}
