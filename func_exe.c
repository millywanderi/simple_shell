/*
 * File: func_exe.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * func_exec - Does appropriate execution
 * @argue: List of user arguements
 *
 * Return: (0) on Success, (-1) on Failure
 */

int func_exec(char *const *argue)
{
	int var;

	var = builtin(argue);
	if (var == 0)
		return (0);

	if (error_msg == 2)
	{
		var = (external_cmd(argue));
		if (var == 0)
		{
			return (0);
		}
	}
	return (-1);
}
