/*
 * File: exe_files.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * external_cmd - identify and execute external commands
 * @argue: cmd table (i.e. list of user args)
 *
 * Return: 0 on Sucess, -1 on Failure
 */
int external_cmd(char *const *argue)
{
	char **path_ar = NULL;
	int status, j;
	pid_t pid;

	if (check_path(argue))
	{
		path_ar = (char **)mng_alloc((char *)path_ar, (sizeof(char *) * 2));
		path_ar[0] = mng_alloc(path_ar[0], (sizeof(char) * (_strlen(argue[0]) + 1)));
		_strncpy(path_ar[0], argue[0], _strlen(argue[0]));
		path_ar[1] = NULL;
	}
	else
		path_ar = path_get(argue);

	for (j = 0; path_ar[j]; j++)
		if (access(path_ar[j], (R_OK | X_OK)) == 0)
		{
			switch ((pid = fork()))
			{
				case -1:
					return (-1);
				case 0:
					execve(path_ar[i], argue, environ);
					error_msg = 1;

					exit(EXIT_FAILURE);
				default:
					if ((waitpid(pid, &status, 0)) == -1)
						return (-1);
					else
						return (0);
			}
		}
	error_msg = 2;
	return (-1);
}

/**
 * builtin - identify and execute external commands
 * @argue: cmd table (i.e. list of user args)
 *
 * Return: 0 on Sucess, -1 on Failure
 */

int builtin(char *const *argue)
{
	built_in funct_p[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"cd", builtin_cd},
		{NULL, NULL}
	};

	int j;
	int (*built_in_funcp)(char *const *argue);

	for (j = 0; func_p[j].cmd; j++)
		if ((_strcmp(argue[0], func_p[j].cmd)) == 0)
		{
			built_in_funcp = func_p[j].fp;

			if ((built_in_funcp(argue)) == 0)
				return (0);

			err_msg = 3;
			return (-1);
		}
	err_msg = 2;
	return (-1);
}
