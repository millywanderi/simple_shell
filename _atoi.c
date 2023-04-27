/*
 * File: _atoi.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

char *_atoi(size_t num, char *mem, int val);
size_t dig_cnt(size_t number);

/**
  * dig_cnt - a function counting digits in a number
  * @number: where to count digits
  * Return: digit counted
  */

size_t dig_cnt(size_t number)
{
	size_t tally = 0;

	while (number != 0)
	{
		number /= 10;
		tally++;
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
