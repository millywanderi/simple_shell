/*
 * File: command_help.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * target_get - create a target copy on environ
 * @variable_n: The env variable name
 *
 * Return: path Success, NULL on Fail
 */

char *target_get(char *variable_n)
{
	size_t p_len = 0;
	size_t n_len = 0;
	size_t j = 0;
	char *path_array = NULL;

	for (; environ[j]; j++)
	{
		if ((_strncmp(variable_n, environ[j], n_len)) == 0)
		{
			p_len = (_strlen(environ[j]) - n_len);
			path_array = mng_alloc(path_array, (sizeof(char) * (p_len + 1)));
			if (!path_array)
			{
				return (NULL);
			}
			_strncpy(path_array, &environ[j][n_len], p_len);

			return (path_array);
		}
	}
	errno = ENOENT;
	return (NULL);
}

/**
 * chd_arg - change a target path
 * @dirg: go to directory
 * Return: 0 Success, 1 on Fail
 */

int chd_arg(char *dirg)
{
	size_t length = 0;
	char *path_array = NULL;
	char *dir_tag = NULL;

	if (chdir(dirg) == 0)
	{
	if  (check_path(&dirg))
	{
		set_OLDPWD();
		set_PWD(dirg);
		return (0);
	}
	else
	{
		dir_tag = target_get("PWD=");
		length = (_strlen(dir_tag) + _strlen(dirg));
		path_array = mng_alloc(path_array, (sizeof(char) * (len + 2)));

		if (!path_array)
		{
			return (-1);
		}
		_strncpy(path_array, dir_tag, _strlen(dir_tag));
		_strcat(path_array, "/");
		_strcat(path_array, dirg);
		set_OLDPWD();
		set_PWD(dir_tag);

		return (0);
	}
	errno = ENOENT;
	return (-1);
	}
}

/**
 * cd_previous - change to previous directory
 * Return: 0 on Success, 1 on Failure
 */

int cd_previous(void)
{
	char *dir_tag = NULL;

	dir_tag = target_get("OLDPWD=");

	if (dir_tag)
	{
		if (chdir(dir_tag) == 0)
		{
			set_OLDPWD();
			set_PWD(dir_tag);

			write(STDOUT_FILENO, dir_tag, (_strlen(dir_tag)));
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}
