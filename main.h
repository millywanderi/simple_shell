#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

#define SIZE 1024
#define ARGS_COUNT 150


void argument(char *buffer, char **argue, int *number);
char *handle_path();
/*int env_print(char **envi);
extern char **environ;
int cdir();*/

#endif
