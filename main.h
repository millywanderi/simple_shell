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
#define TOTAL_ARGS 1024
extern char **environ;

int compare_argue(const char *str1, const char *str2);
void argument(char *buffer, char **argue, int *number);


/*atoi function*/
size_t dig_cnt(size_t number);
char *_atoi(size_t num, char *mem, int val);

/*major functions*/
char *str_tok(char *tok);
size_t tok_count(char *str);
size_t tok_len(char *str, size_t speci);
int alloc_mem(char *mem);
void shift_buf(char *mem, ssize_t n);
ssize_t get_line(char **buffer);
ssize_t buffer_cpy(char **dest, char **src, ssize_t *begin);
char **handle_path(char *const *argue);
size_t check_path(char *const *argue);
size_t len_way(char *ptr_env);
size_t cnt_path(char *way);
int _printenv(char *const *argue);
int exiting(char * const *argue);
int _itoi(char *str);
void print_error(size_t loop, char *argue, char **toks);
char *create_err(char *custom, char **toks);
int number(char str);

/*string functions*/
size_t _strlen(const char *string);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_revstr(char *str);
char *_strcat(char *dest, const char *src);
char *_strncpy(char *s1, const char *s2, size_t n);


#endif
