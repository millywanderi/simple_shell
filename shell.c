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
	int status, number = 0;
	size_t buffersize = 0;
	pid_t child;
	char get_line, *argue[ARGS_COUNT], *way, *command = "$ ", *buffer = NULL;

	while (1)
	{
	write(STDOUT_FILENO, command, 2);
	fflush(stdout);
	get_line = getline(&buffer, &buffersize, stdin);
	if (get_line == -1)
		break;
	buffer[strcspn(buffer, "\n")] = '\0';
	if (strcmp(argue[0], "env") == 0)
	{
		env_print();
		continue;
	}
	argument(buffer, argue, &number);
	way = handle_path(argue[0]);
	child = fork();
	if (child == -1)
	{
		perror("Error ");
		exit(1);
	}
	else if (child == 0)
	{
		if (execv(way, argue) == -1)
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
