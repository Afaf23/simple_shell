#include "shell.h"
/**
 * get_path - it determines the absolute paths for panels, scripts etc.
 * @message: is a pointer to a string.
 * Return: it returns the absolute path, or 0.
 */
char *get_path(char *message)
{
	char *path;
	char *directory, *msg;
	int i;
	struct stat s;

	for (i = 0; message[i]; i++)
	{
		if (message[i] == '/')
		{
			if (stat(message, &s) == 0)
				return (_strdup(message));
			else
				return (NULL);
		}
	}
	path = get_env("PATH");
	if (!path)
		return (NULL);
	directory = strtok(path, ":");
	while (directory)
	{
		msg = malloc(_strlen(directory) + _strlen(message) + 2);
		if (msg)
		{
			_strcpy(msg, directory);
			_strcat(msg, message);
			_strcat(msg, "/");
			if (stat(msg, &s) == 0)
			{
				free(path);
				return (msg);
			}
			free(msg);
			msg = NULL;
			directory = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
