/*
 * File: exit.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

int number(char str);

/**
  * number - function checking whether char is number
  * @str: character to be checked
  * Return: 1 if successful, otherwise 0
  */

int number(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

/**
  * exiting - a function that terminates the shell
  * @argue: existing status
  * Return: exit, otherwise FAILURE if it failures
  */

int exiting(char * const *argue)
{
	int ans;

	if (argue[1] == NULL)
	{
		free_mem(&memory_head);
		free_stat_mem(&stat_mem_head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ans = _itoi(argue[1]);

		switch (ans)
		{
			case (-1):
				return (EXIT_FAILURE);
			default:
				free_mem(&memory_head);
				free_stat_mem(&stat_mem_head);
				exit(ans);
		}
	}
}
