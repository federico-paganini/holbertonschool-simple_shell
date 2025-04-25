#ifndef _GATES_OF_SHELL_H
#define _GATES_OF_SHELL_H

/* Standard libraries included globally in the project*/
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Function prototypes used to process the args*/
char *get_line(char **);
char **get_args(char *);
char **tokenize_line(char *);
void handle_sigint(int);
void setup_signal(void);

/*Function prototypes used to process the execution path*/
char *interpreter(char **, char **, char **, int *);
char **tokenize_path(char *);
char *find_path(char *, char **);
char *_getenv(char *, char **);

/*Execute function*/
int execute(char *, char **, char **);

/*Function prototypes used to handle built-in*/
int builtin_handler(char **, char **, char **, int status);
void exit_builtin(char **, char **, char **, int status);
int env_builtin(char **, char **);

/*General utilities prototypes functions*/
int args_count(char *);
int _wlen(char *);
void free_vector(char **);
char **copy_envp(char **);
int valid_exit_status(char *);
char *_strdup(char *);
int _strcmp(char *, char *);
int _atoi(char *);

#endif
