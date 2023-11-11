#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys:stat.h>
#include <errno.h>
#include <fcntl.h>

/* prototypes */
void we_print(const char *string);



#define DELIM " \t\n"
extern char **envrmt;



/**
 * freearray - Frees the memory allocated to an array of strings
 * function takes an array of strings and frees memory
 * @array: The array of strings to be freed.
 */
void freearray(char **array);






int _execute(char **command, char **argv);
char *read_line(void);
char **tokeniser(char *line);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *get_env(char *var);

#endif
