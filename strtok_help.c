/*
 * File: strtok_help.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

size_t tok_len(char *str, size_t speci);
size_t tok_count(char *str);

/**
  * tok_len - a function that counts token specification
  * @str: token string
  * @speci: shows the specific area for the token
  *  Return: len
  */

size_t tok_len(char *str, size_t speci)
{
	size_t len = 0;
	size_t now = 0, cur = 0;

	while (cur < speci)
	{
		while (str[now] == ' ' || str[now] == '\t')
			now++;
		if (str[now] != '\0' && str[now] != ' ' && str[now] != '\t')
		{
			cur++;
			while (str[now] != '\0' && str[now] != ' ' && str[now] != '\t')
			{
				if (cur == speci)
					len++;
				now++;
			}
		}
	}
	return (len);
}

/**
  * tok_count - a function that count tokens
  * @str: string to be counted
  * Return: sum of tokens
  */

size_t tok_count(char *str)
{
	size_t amount = 0, m = 0;

	while (str[m] != '\0')
	{
		if (str[m + 1] == ' ' || str[m + 1] == '\t' || str[m + 1] == '\0')
			amount++;
		m++;
	}
	return (amount);
}
