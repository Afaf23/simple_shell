#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/* prototypes */
void we_print(const char *string);


#define DELIM " \t\n"

/**
 * freearray - Frees the memory allocated to an array of strings
 * function takes an array of strings and frees memory
 * @array: The array of strings to be freed.
 */
void freearray(char **array);



extern char **envir;

char **split(char *line);
int _execute(char **command, char **argv, int index);
char *read_line(void);
char **tokeniser(char *line);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *get_env(char *var);
char *get_path(char *message);
void PrintError(char *nsh, char *cmd, int index);
char *_itoa(int n);
void rev_str(char *str, int len);
void p_envrmt(char **command, int *status);
void exit_sh(char **command, int *status);
void handle_b(char **command, char **argv, int *status, int index);
int exit_builtin(char *messsage);
#endif
