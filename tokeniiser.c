#include "shell.h"

/**
 * tokeniser - Tokenize a string
 * @line: line
 *
 * Return: An array of strings   NULL if allocation fail
 */
char **tokeniser(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int ctr = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);

	token = strtok(tmp, DELIM);
	while (token)
	{
		ctr++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);

	command = malloc(sizeof(char *) * (ctr + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		command(i) = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
		free(line);
		command[i] = NULL;
		return (command);

}
