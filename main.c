#include "shell.h"

char **split(char *line);

/**
 * main - main function of shell
 * @ac: arguments count
 * @argv: arguments
 * Return: always 0
 */

int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, index = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
<<<<<<< HEAD
			write(STDOUT_FILENO, "\n", 1);
=======
			{
				write(STDOUT_FILENO, "\n", 1);
			}
>>>>>>> 0002da9e4dbcabbf99605d7ec139e14b0e32fe95
			return (status);
		}
		index++;

		if (!command)
			continue;
		if (exit_builtin(command[0]))
			handle_b(command, argv, &status, index);
		else
		status = _execute(command, argv, index);

		freearray(command);
	}

}
