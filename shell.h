#ifndef _GATES_OF_SHELL_H
#define _GATES_OF_SHELL_H

/* Standard libraries included globally in the project*/
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Function prototypes used to process the args*/
char *get_line(char **);
char **get_args(char *);
char **tokenize_line(char *);

/*Function prototypes used to process the execution path*/
char *interpreter(char **, char **);
char **tokenize_path(char *);
char *find_path(char *);

/*Execute function*/
void execute(char *, char **, char **);

/*General utilities prototypes functions*/
int args_count(char *);
int _wlen(char *);
void free_vector(char **);
char **copy_envp(char **);

#endif

