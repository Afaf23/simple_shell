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
