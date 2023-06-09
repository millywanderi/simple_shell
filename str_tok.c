/*
 * File: str_tok.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

char **str_tok(char *tok);

/**
  * str_tok - a function that tokenize
  * @tok: string to be tokenized
  * Return: array
  */

char **str_tok(char *tok)
{
	size_t amount, size;
	char **token = NULL;
	size_t len = 0, cur = 1;
	size_t m = 0, set_line = 0, cpy_tok = 0;

	amount = tok_count(tok);
	if (amount == 0)
	{
		return (NULL);
	}
	size = (amount + 1) * (sizeof(char *));
	token = (char **) mng_alloc((char *)token, size);
	if (token == NULL)
		return (NULL);
	while (cur <= amount)
	{
		len = tok_len(tok, cur);
		size = (len + 1) * (sizeof(char));
		if (token[m] == NULL)
		{
			return (NULL);
		}
		while (tok[set_line] == ' ' || tok[set_line] == '\t')
			set_line++;
		while (cpy_tok < len)
		{
			token[m][cpy_tok] = tok[set_line];
			cpy_tok++;
			set_line++;
		}

		token[m][cpy_tok] = '\0';
		cur++;
		m++;
	}
	token[m] = NULL;
	return (token);
}
