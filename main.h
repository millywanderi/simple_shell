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
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>

#define SIZE 1024
#define ARGS_COUNT 150
#define BUFFER_SIZE 1024
#define TOTAL_ARGS 1024

/**
 * struct alloc_history - struct memory allocation
 * @memory_ptr: memory pointer
 * @next: next node
 */

typedef struct alloc_history
{
	char *memory_ptr;
	struct alloc_history *next;

} memory_list;

/**
 * struct built_ins - catalogue built-in functions
 * @cmd: command name
 * @fp: pointer to named function
 */
typedef struct built_ins
{
	char *cmd;
	int (*fp)(char * const*);
} built_in;

/* Main program */
void sig_recieve(int signal);
void sig_recieve(int signal __attribute__((unused)));
int main(int ac __attribute__((unused)), char **argue);

/* Memory program functions */
char *mng_alloc(char *ptr, size_t size);
char *re_alloc(char *ptr, size_t new_allocsize);
void free_mem(memory_list **head);
memory_list *add_memory(memory_list **head, char *ptr);
char *_setmem(char *m, char j, unsigned int d);
void free_stat_mem(memory_list **head);

/* extern variables */
extern char **environ;
extern memory_list *memory_head;
memory_list *memory_head;
extern memory_list *stat_mem_head;
memory_list *stat_mem_head;
extern size_t error_msg;
size_t error_msg;

/* execute */
int func_exec(char *const *argue);
int external_cmd(char *const *argue);
int cd_builtin(char *const *argue);
int builtin(char *const *argue);

/* change dir command.c */
int chd_HOME(void);
int chd_cur(void);
int chd_parent(void);
int chd_user(char *argue);
char *target_get(char *variable_n);
int chd_arg(char *dirg);
int cd_previous(void);

void argument(char *buffer, char **argue, int *number);

/* set pwd functions */
int set_PWD(char *val_v);
int set_OLDPWD(void);

/*atoi function*/
size_t dig_cnt(size_t number);
char *_atoi(size_t num, char *mem, int val);

/*major functions*/
char **str_tok(char *tok);
size_t tok_count(char *str);
size_t tok_len(char *str, size_t speci);
int alloc_mem(char *mem);
void shift_buf(char *mem, ssize_t n);
ssize_t get_line(char **buffer);
ssize_t buffer_cpy(char **dest, char *src, ssize_t *begin);
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
