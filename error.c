/*
 * File: error.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
  * print_error - a function printing error message
  * @loop: shell looping
  * @argue: holds shell name
  * @toks: holds tokens with error message
  */

void print_error(size_t loop, char *argue, char **toks)
{
	size_t len_toks = _strlen(toks[0]), len_toks2 = _strlen(toks[1]);
	size_t len_argue = _strlen(argue);
	char *tag = NULL, *custom = NULL, *count = NULL;
	size_t len_custom, len_tag;
	size_t dig = dig_cnt(loop);
	size_t alloc_sum = len_argue + dig + len_toks + len_toks2 + 6;

	switch (error_msg)
	{
		case (2):
			custom = mng_alloc(custom, (sizeof(char) * 8));
			custom = ": failed\0";
			break;
		case (3):
			custom = create_err(custom, toks);
			if (custom == NULL)
				return;
			break;
		default:
			perror(argue);
			return;
	}
	count = mng_alloc(count, (sizeof(char) * (dig + 1)));
	_atoi(loop, count, 10);
	len_custom = _strlen(custom);
	alloc_sum += len_custom;
	tag = mng_alloc(tag, sizeof(char) * alloc_sum);
	_strncpy(tag, argue, len_argue);
	_strcat(tag, ": ");
	_strcat(tag, custom);
	_strcat(tag, ": ");
	_strcat(tag, toks[0]);
	_strcat(tag, custom);
	if (error_msg == 3)
		_strcat(tag, toks[0]);
	_strcat(tag, "\n");
	len_tag = _strlen(tag);
	write(STDERR_FILENO, tag, len_tag);
}
