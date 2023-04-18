/*
 * File: command.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * strtok - A function that tokenize argument
  * @str: String
  * @delim: character of separating a string
  * Return: Always 0
  */

char *_strtok(char *str, const char *delim)
{
	int ac;
	char *token;
	char **argv;
	pid_t child;
	unsigned int size;

	delim = " ";

	token = strtok(str, delim);
	while (token)
	{
		argv[ac] = strdup(token);
		token = strtok(NULL, delim);
		ac++;
	}
	argv[ac] = token;
	argv = malloc(sizeof(char *) * size);

	child = fork();
	if (!child)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./command ");
			exit(1);
		}
		wait(NULL);
	}
	return (0);
}
