/*
 * File: path.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * handle_path - a function that handles a path
 * @argue: arguments
 * Return: NULL
 */

char *handle_path(char *argue)
{
	char *cur_path, *directory, *path_cpy;
	char *final_path;

	if (strncmp(argue, "/bin/", 5) == 0)
	{
		if (access(argue, F_OK) == 0)
		{
			return (argue);
		}
		else
			return (NULL);
	}
	if (strcmp(argue, "exit") == 0)
	{
		close_shell();
	}

	cur_path = getenv("PATH");
	path_cpy = strdup(cur_path);
	directory = strtok(path_cpy, ":");

	while (directory != NULL)
	{
		final_path = malloc(strlen(directory) + strlen(argue) + 2);
		sprintf(final_path, "%s/%s", directory, argue);
		if (access(final_path, F_OK) == 0)
		{
			free(path_cpy);
			return (final_path);
		}
		free(final_path);
		directory = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * close_shell - terminate the shell
 */

void close_shell(void)
{
	exit(0);
}
