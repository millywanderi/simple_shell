/*
 * File: command.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * cd_builtin - A function that change directory
  * @argue: Vector argument
  * Return: 0 on Success, -1 on fail
  */

int cd_builtin(char *const *argue)
{
	if (argue[1] == NULL || !(_strcmp(argue[1], "~")))
	{
		if (chd_HOME())
			return (-1);
	}
	else if (!(_strcmp(argue[1], ".")))
	{
		if (chd_cur())
			return (-1);
	}
	else if (!(_strcmp(argue[1], "..")))
	{
		if (chd_parent())
			return (-1);
	}
	else if (!(_strcmp(argue[1], "-")))
	{
		if (cd_previous())
			return (-1);
	}
	else if ((!(_strncmp(argue[1], "~", 1)) && (argue[1][1] != '\0')))
	{
		if (chd_user(argue[1]))
			return (-1);
	}
	else
	{
		if (chd_arg(argue[1]))
			return (-1);
	}
	return (0);
}

/**
 * chd_HOME - change home directory
 * Return: 0 on Success, -1 on Failure
 */

int chd_HOME(void)
{
	char *dir_tag = NULL;

	dir_tag = target_get("HOME=");

	if (dir_tag)
	{
		if (chdir(dir_tag) == 0)
		{
			set_OLDPWD();
			set_PWD(dir_tag);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}

/**
 * chd_cur - change home directory
 * Return: 0 on Success, -1 on Failure
 */

int chd_cur(void)
{
	char *dir_tag = NULL;

	dir_tag = target_get("PWD=");

	if (dir_tag)
	{
		if (chdir(dir_tag) == 0)
		{
			set_OLDPWD();
			set_PWD(dir_tag);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}

/**
 * chd_parent - change to parent directory
 * Return: 0 on Success, 1 on Failure
 */

int chd_parent(void)
{
	char *dir_tag = NULL;
	size_t j;

	dir_tag = target_get("PWD=");

	if (dir_tag)
	{
		for (j = _strlen(dir_tag); dir_tag[j] != '/';)
			j--;

		for (; dir_tag[j]; j++)
			dir_tag[j] = '\0';

		if (chdir(dir_tag) == 0)
		{
			set_OLDPWD();
			set_PWD(dir_tag);
			return (0);
		}
	}
	return (-1);
}

/**
 * chd_user - move to user home
 * @argue: User name
 *
 * Return: 0 on Success, 1 on Failure
 */

int chd_user(char *argue)
{
	char *user_dir = NULL;
	size_t user_len = _strlen(argue);

	user_dir = mng_alloc(user_dir, (sizeof(char) * (6 + user_len)));

	if (!user_dir)
		return (-1);

	_strncpy(user_dir, "/home/", 6);
	_strcat(user_dir, &argue[1]);

	if (chdir(user_dir) == 0)
	{
		set_OLDPWD();
		set_PWD(user_dir);
		return (0);
	}

	errno = ENOENT;
	return (-1);
}
