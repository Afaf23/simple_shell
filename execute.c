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
		if (execve(msg, command, envir) == -1)
		{
			free(msg);
<<<<<<< HEAD
=======
			msg = NULL;
>>>>>>> 0002da9e4dbcabbf99605d7ec139e14b0e32fe95
			freearray(command);
		}
	}
	else
	{
		waitpid(ch, &status, 0);
		freearray(command);
<<<<<<< HEAD
		/*free(msg),*/ msg = NULL;
=======
		free(msg);
		msg = NULL;
>>>>>>> 0002da9e4dbcabbf99605d7ec139e14b0e32fe95
	}
	return (WEXITSTATUS(status));
}
