#ifndef _GATES_OF_SHELL_H
#define _GATES_OF_SHELL_H

/* Standard libraries included globally in the project*/
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/*Function prototypes used across the shell proyect*/
char *get_line(void);
char **check_validity(char *);
char **tokenize_line(char *);

/*General utilities prototypes functions*/
int args_count(char *);
int _wlen(char *);
void print_args(char **);
void free_all(char **);

#endif
