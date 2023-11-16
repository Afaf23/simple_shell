#include "shell.h"
/**
 * get_env - returns a pointer to the variable's value.
 * @var: pointer to a string.
 * Return: it returns pointer if successful, NULL If the varname is not found.
 */
char *get_env(char *var)
{
	char *temp, *brk, *v, *env;
	int i;

	for (i = 0; envir[i]; i++)
	{
		temp = _strdup(envir[i]);
		brk = strtok(temp, "=");
		if (_strcmp(brk, var) == 0)
		{
			v = strtok(NULL, "\n");
			env = _strdup(v);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}
