/*
 * Auth: Justin Mwaipe, Millicent Wanderi
 * File: function.c
 */

#include "main.h"

/**
  * _strcspn - function used for scanning
  * @str: string
  * @good: string following str
  * Return: Always 0
  */

size_t _strcspn(const char *str, const char *good)
{
	const char *m, *n;
	size_t number = 0;

	for (m = str; *m != '\0'; m++)
	{
		for (n = good; *n != '\0'; n++)
		{
			if (*m == *n)
			{
				return (number);
			}
		}
		number++;
	}
	return (number++);
}
