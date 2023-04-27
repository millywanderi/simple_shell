/*
 * File: env.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * _printenv - a function printing environment
  * @argue: command arguement
  * Return: if successful 0, otherwise -1
  */

int _printenv(char *const *argue)
{
	size_t length, m;

	if (!argue[1])
	{
		for (m = 0; environ[m]; m++)
		{
			length = _strlen(environ[m]);
			if ((write(STDOUT_FILENO, environ[m], length)) == -1)
				return (-1);
			if ((write(STDOUT_FILENO, environ[m], length)) == -1)
				return (-1);
		}
	}
	else
	{
		errno = ENOENT;
		return (-1);
	}
	return (0);
}
