/*
 * File: path.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * compare_argue - a function that compares to arguement
 * @str1: first argue
 * @str2: second argue 
 */

int compare_argue(const char *str1, const char *str2)
{
	while (*str1 && (*str2))
	{
		str1++;
		str2++;
	}
	return (*(const unsigned char *)str1 -*(const unsigned char *)str2);
}
