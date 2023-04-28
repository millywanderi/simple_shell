/*
 * File: set_pwd.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * set_OLDPWD - set path value of environ var OLDPWD
 *
 * Return: 0 on Success, 1 on Failure
 */

int set_OLDPWD(void)
{
	size_t j;
	char *update = NULL;
	char *pwd_ref = "PWD=";
	char *owd_ref = "OLDPWD=";
	size_t pwd_len = 0;
	char *pwd = NULL;

	for (j = 0; environ[j]; j++)
	{
		if ((_strncmp(pwd_ref, environ[j], 4)) == 0)
			pwd = &environ[j][4];
	}
	if (!pwd)
		return (-1);

	pwd_len = _strlen(pwd);

	j = 0;
	while (environ[j])
	{
		if ((_strncmp(owd_ref, environ[j], 7)) == 0)
		{
			environ[j] = re_alloc(update, (sizeof(char) * (7 + pwd_len + 1)));
			if (!environ[j])
				return (-1);
			add_memory(&stat_mem_head, environ[j]);

			_strncpy(environ[j], owd_ref, 7);
			_strcat(environ[j], pwd);

			return (0);
		}
		j++;
	}
	errno = ENOENT;
	return (-1);
}

/**
 * set_PWD - create path value environ var PWD
 * @val_v: value of variable
 *
 * Return: 0 on Success, 1 on Failure
 */

int set_PWD(char *val_v)
{
	size_t i = 0;
	char *update = NULL;
	size_t val_len;
	size_t name_len = 4;
	char *name = "PWD=";

	val_len = _strlen(val_v);

	i = 0;
	while (environ[i])
	{
		if ((_strncmp(name, environ[i], name_len)) == 0)
		{
			environ[i] = re_alloc(update, (sizeof(char) * (name_len + val_len + 1)));
			if (!environ[i])
				return (-1);

			add_memory(&stat_mem_head, environ[i]);
			_strncpy(environ[i], name, name_len);
			_strcat(environ[i], value);

			if (environ[i][name_len + val_len - 1] == '/')
			{
				environ[i][name_len + val_len - 1] = '\0';
			}
			return (0);
		}
		i++;
	}

	errno = ENOENT;
	return (-1);
}
