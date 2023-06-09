/*
 * File: string.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

size_t _strlen(const char *string);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);

/**
  * _strlen - A function checking string length
  * @string: string which length is checked
  * Return: string length, otherwide 0 if it fails
  */

size_t _strlen(const char *string)
{
	size_t length = 0;

	if (string != NULL)
	{
		while (*string != '\0')
		{
			length++;
			string++;
		}
	}
	return (length);
}

/**
  * _strcmp - a function that compares 2 strings
  * @str1: first string to compare
  * @str2: second string to compare
  * Return: number
  */

int _strcmp(const char *str1, const char *str2)
{
	int m = 0;

	while (str1[m] != '\0' || str2[m] != '\0')
	{
		if (str1[m] < str2[m])
			return (str1[m] - str2[m]);
		if (str1[m] > str2[m])
			return (str1[m] - str2[m]);
		m++;
	}
	return (0);
}

/**
  * _strncmp - a function comparing strings
  * @str1: first string
  * @str2: second string
  * @n: number of strings to be compared
  * Return: Always 0
  */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t m = 0;

	while (m < n && (str1[m] != '\0' || str2[m] != '\0'))
	{
		if (str1[m] < str2[m])
			return (str1[m] - str2[m]);
		if (str1[m] > str2[m])
			return (str1[m] - str2[m]);
		m++;
	}
	if (m < n && str2[m] != '\0')
		return (str1[m] - str2[m]);
	return (0);
}
