/*
 * File: shell.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)

{
	size_t buffersize = 0;
	char *buffer = NULL, *buffer_cpy = NULL;
	pid_t child;
	int status;

	while (1)
	{
	printf("#cisfun$ ");
	fflush(stdout);
	int get_line = getline(&buffer, &buffersize, stdin);

	if (get_line == -1)
		break;
	buffer[strcspn(buffer, "\n")] = '\0';

	char *_strtok(char *str, const char *delim);
	buffer_cpy = strdup(buffer);
	child = fork();
	if (child == -1)
	{
		perror("Error ");
		exit(1);
	}
	else if (child == 0)
	{
		if (execl(buffer, buffer, (char *) NULL) == -1)
		{
			perror("./shell ");
			exit(1);
		}
		exit(0);
	}
	else
		waitpid(child, &status, 0);
	}
	free(buffer);
	return (0);
}
