/*
 * File: path.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

char **handle_path(char *const *argue);

/**
 * handle_path - a function that handles a path
 * @argue: cmd
 * Return: array pointer
 */

char **handle_path(char *const *argue)
{
	size_t m = 0, count, envi = 0;
	char **way = NULL;
	char *refer = "PATH=";
	size_t conc_size;
	char *ptr_env = NULL;

	while (environ[envi])
	{
		if (_strncmp(refer, environ[envi], 5) == 0)
		{
			ptr_env = &environ[envi][5];
			count = cnt_path(ptr_env);
			way = (char **)mng_alloc((char *)way, (sizeof(char *) * (count + 1)));
			while (m < count)
			{
				conc_size = (len_way(ptr_env) + _strlen(argue[0]) + 2);
				way[m] = mng_alloc(way[m], (sizeof(char) * conc_size));
				_strncpy(way[m], ptr_env, len_way(ptr_env));
				_strcat(way[m], "/");
				_strcat(way[m], argue[0]);

				ptr_env = (ptr_env + (len_way(ptr_env) + 1));
				m++;
			}
			way[m] = NULL;
			return (way);
		}
		envi++;
	}
	return (NULL);
}
