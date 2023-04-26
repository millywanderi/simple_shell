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
#define BUFFER_SIZE 1024
extern char **environ;

int compare_argue(const char *str1, const char *str2);
void argument(char *buffer, char **argue, int *number);
char *handle_path(char *argue);
void close_shell(void);
void env_print(void);
void cdir(void);

#endif
