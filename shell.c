/*
 * File: shell.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

void sig_recieve(int signal);

/**
 * sig_recieve - Display the comd line again if [Ctrl + c]
 * @signal: Attribute
 */

void sig_recieve(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Entry point
 * @ac: Count the elements in argue array
 * @argue: Array of arguements
 * Return: Always 0
 */

int main(int ac __attribute__((unused)), char **argue)
{
	char *buffer = NULL, **toks = NULL;
	size_t buffersize = 1;

	while (1)
	{
		buffer = NULL;
		toks = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		signal(SIGINT, sig_recieve);

		if ((get_line(&buffer)) == 0)
		{
			free_mem(&memory_head);
			free_stat_mem(&stat_mem_head);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (buffer)
			toks = str_tok(buffer);

		if (toks)
		{
			if ((func_exec(toks)) == -1)
				print_error(buffersize, argue[0], toks);
		}
		free_mem(&memory_head);

		buffersize++;
	}
	free_stat_mem(&stat_mem_head);
	return (0);
}
