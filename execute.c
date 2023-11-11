#include "shell.h"

int _execute(char **command, char **argv);
{
	pid_t ch;
	int status;

	ch = fork();
	if (ch == 0)
	{
		if (execve(command[0], command, envrmt) == -1)
		{
			perror(argv[0]);
			freearray(command);
			exit(0);
		}
	}
	else
	{
		waitpid(ch, &status, 0);
		freearray(command);
	}
	return (WEXITSTATUS(status));
}
