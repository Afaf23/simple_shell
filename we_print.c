#include "shell.h"

/**
 * we_print -a function that prints a string.
 * @string: the string to be printed
 */
void we_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
