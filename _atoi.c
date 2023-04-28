/*
 * File: _atoi.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

char *_atoi(size_t num, char *mem, int val);
size_t dig_cnt(size_t number);
int _itoi(char *str);

/**
  * _itoi - a function converting string to number
  * @str: string to undergo conversion
  * Return: str in success, otherwise -1
  */

int _itoi(char *str)
{
	int m = 0;
	int ans = 0;

	if (str[m] == '-')
	{
		return (-1);
	}
	for (; str[m] != '\0'; m++)
	{
		if (number(str[m]))
		{
			ans = ans * 10 + str[m] - '0';
		}
		else
		{
			return (-1);
		}
	}
	if (str > 2147183647)
	{
		return (-1);
	}
	else
	{
		return (ans);
	}
}
/**
  * dig_cnt - a function counting digits in a number
  * @number: where to count digits
  * Return: digit counted
  */

size_t dig_cnt(size_t number)
{
	size_t tally = 0;

	for (; number != 0; tally++)
	{
		number /= 10;
	}
	return (tally);
}
/**
  * _atoi - a function for converting numbers to strings
  * @num: digit to be converted
  * @mem: stores the string
  * @val: strin's value
  * Return: string
  */

char *_atoi(size_t num, char *mem, int val)
{
	size_t remain = 0;
	int m = 0, sig = 1;

	if (num == 0)
	{
		mem[m++] = '\0';
		mem[m] = '\0';
	}
	while (num)
	{
		remain = num % val;
		mem[m++] = '0' + remain;
		num /= val;
	}
	if (sig < 0)
		mem[m] = '\0';
	return (_revstr(mem));
}
