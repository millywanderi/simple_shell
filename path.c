/*
 * File: path.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * handle_path - a function that handles a path
 * Return: NULL
 */

char *handle_path()
{
	char *cur_path, *path_cpy, *directory;
	char *buffer_path, *entry = NULL;
	char *delim = ":";

	cur_path = getenv("PATH");
	if (cur_path == NULL)
	{
		return (NULL);
	}
	path_cpy = strdup(cur_path);
	directory = strtok(path_cpy, delim);
	if (directory == NULL)
	{
		exit(1);
	}
	else
	{
		buffer_path = malloc(sizeof(char *));
		sprintf(buffer_path, "%s/%s", directory, entry);
		if (access(buffer_path, X_OK) == 0)
		{
			free(path_cpy);
			return (buffer_path);
		}
		free(buffer_path);
		directory = strtok(NULL, delim);
	}
	free(path_cpy);
	return (NULL);
}
