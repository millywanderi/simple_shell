/*
 * File: error_helper.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * create_err - a function creating or printing error
  * @custom: saves error message
  * @toks: holds tokenised error message
  * Return: NULL or pointer
  */

char *create_err(char *custom, char **toks)
{
	size_t toks1 = _strlen(toks[0]);
	size_t toks2 = _strlen(toks[1]);

	if (toks1 == 4)
	{
		custom = mng_alloc(custom, (sizeof(char) * 10));
		custom = ": error: \0";
		return (custom);
	}
	else if (toks1 == 2)
	{
		custom = mng_alloc(custom, (sizeof(char) * 9));
		custom = ": Error \0";
		return (custom);
	}

	custom = mng_alloc(custom, sizeof(char) * toks1 + toks2 + 5);

	_strncpy(custom, toks[0], toks1);
	_strcat(custom, ": '");
	_strcat(custom, toks[1]);
	_strcat(custom, "'");

	errno = ENOENT;

	perror(custom);

	return (NULL);
}
