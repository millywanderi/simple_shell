/*
 * File: command.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * argument - A function that tokenize argument
  * @str: String
  * @delim: character of separating a string
  * @argv: Vector argument
  * Return: Always 0
  */

extern char **environ;

int argument()
{
	char *str = NULL;
	char *delim;
	char **argv;
	char **envi;
	int ac = 0;
	argv = NULL;
	envi = environ;

	delim = " \n";

	argv[ac] = strtok(str, delim);
	while (argv[ac])
	{
		ac++;
		argv[ac] = strtok(NULL, delim);
	}
	if (argv[0] == NULL)
		return (1);

	if (strcmp(argv[0], "cd") == 0)
	{
		handle_path();
		return(0);
	}
	else if (strcpy(argv[0], "exit") == 0)
		return (-1);
	else if (strcpy(argv[0], "env") == 0)
	{
		env_print(envi);
		return (0);
	}
	return (0);
}

/**
  * env_print - A function that prints the environment
  * @env: array of the environment
  */

extern char **environ;

void env_print(char **envi)
{
	envi = environ;

	while (*envi != NULL)
	{
		printf("%s\n", *envi);
		envi++;
	}
}
