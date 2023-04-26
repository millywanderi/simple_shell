/*
 * File: command.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * argument - A function that tokenize argument
  * @buffer: pointer array of arguments
  * @number: argument count
  * @argue: Vector argument
  * Return: Always 0
  */

void argument(char *buffer, char **argue, int *number)
{
	char *tok;
	*number = 0;

	tok = strtok(buffer, " ");
	while (tok != NULL && *number < ARGS_COUNT - 1)
	{

		argue[(*number)++] = tok;
		tok = strtok(NULL, " ");
	}
	if (*number == ARGS_COUNT - 1 && strtok(NULL, " ") != NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	argue[*number] = NULL;
}

/**
  * env_print - A function that prints the environment
  */

void env_print(void)
{
	char **envi = environ;
	int m = 0;

	while (*envi)
	{
		while ((*envi)[m])
		{
			++m;
		}
		write(1, *envi, m);
		write(1, "\n", 1);
		++envi;
	}
}
