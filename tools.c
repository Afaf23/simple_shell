#include "shell.h"
/**
 * freearray - Frees the memory allocated to an array of strings
 * function takes an array of strings and frees memory
 * @array: The array of strings to be freed.
 */
void freearray(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
}
void PrintError(char *nsh, char *cmd, int index)
{
<<<<<<< HEAD
	char *idx; char format[15] = ": not found\n";
=======
	char *idx; 
	char format[] = ": not found\n";
>>>>>>> 0002da9e4dbcabbf99605d7ec139e14b0e32fe95

	idx = _itoa(index);
	write(STDERR_FILENO, nsh, _strlen(nsh));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, format, _strlen(format));
	free(idx);
}
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	rev_str(buffer, i);
	return (_strdup(buffer));
}
void rev_str(char *str, int len)
{
	char temp;
	int j = 0;
	int f = len - 1;

	while (j < f)
	{
		temp = str[j];
		str[j] = str[f];
		str[f] = temp;
		j++;
		f--;
	}
}

