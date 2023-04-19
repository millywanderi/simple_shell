/*
 * File: command.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * argument - A function that tokenize argument
  * @str: String
  * @delim: character of separating a string
  * Return: Always 0
  */

char *argument(char *str, const char *delim, char **argv)
{
	int ac;
	argv = NULL;
	/*calling path and env func*/
	pid_t child;
	unsigned int size = 0;

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
		/*call env function*/
		return (0);
	}
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
