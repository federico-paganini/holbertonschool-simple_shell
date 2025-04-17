#ifndef _GATES_OF_SHELL_H
#define _GATES_OF_SHELL_H

/* Standard libraries included globally in the project*/
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

/*Function prototypes used across the shell proyect*/
char *get_line(void);
char **check_validity(char *);

#endif
