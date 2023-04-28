/*
 * File: path_helper.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

size_t check_path(char *const *argue);
size_t len_way(char *ptr_env);
size_t cnt_path(char *way);

/**
  * len_way - a function taking the current path length
  * @ptr_env: current path pointer
  * Return: path len
  */

size_t len_way(char *ptr_env)
{
	size_t m = 0;

	if (ptr_env)
	{
		while (ptr_env[m] != ':' && ptr_env[m] != '\0')
		{
			m++;
		}
	}
	return (m);
}

/**
  * check_path - a function checking inclusion of path in command name
  * @argue: command arguement
  * Return: 1 upon success, otherwise 0
  */

size_t check_path(char *const *argue)
{
	size_t pathname = 0;
	size_t m = 0;

	for (; argue[0][m]; m++)
	{
		if (argue[0][m] == '/')
		{
			pathname = 1;
			break;
		}
	}
	return (pathname);
}

/**
  * cnt_path - a function counting paths
  * @way: shows the environment line
  * Return: path number, otherwise 0
  */

size_t cnt_path(char *way)
{
	size_t m = 0;
	size_t count = 0;

	if (!way)
	{
		return (0);
	}
	while (way[m])
	{
		if (way[m + 1] == ':' || way[m + 1] == '\0')
		{
			count++;
		}
		m++;
	}
	return (count);
}
