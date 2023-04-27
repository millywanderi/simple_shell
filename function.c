/*
 * Auth: Justin Mwaipe, Millicent Wanderi
 * File: function.c
 */

#include "main.h"

char *_revstr(char *str);
char *_strcat(char *dest, char *src);
char *_strncpy(char *s1, char *s2, size_t n);

/**
  * _revstr - a function that reverses a string
  * @str: string to be reversed
  * Return: reversed string
  */

char *_revstr(char *str)
{
	int m = 0, n = 0, len = 0, size = 0;
	char *reverse = str;
	char mem;

	len = _strlen(str);
	if ((len % 2) == 0)
		size = (len / 2);
	else
		size = (len - 1) / 2;
	for (m = len - 1; m >= size; n++, m--)
	{
		mem = reverse[n];
		reverse[n] = str[m];
		str[m] = mem;
	}
	return (str);
}

/**
  * _strncpy - a function that copies s2 to s1
  * @s1: first string
  * @s2: second string
  * @n: number of memeory to be copied
  * Return: s1
  */

char *_strncpy(char *s1, char *s2, size_t n)
{
	size_t m = 0;

	while (m < n)
	{
		if (s2[m] == '\0')
			break;
		s1[m] = s2[m];
		m++;
	}
	s1[m] = '\0';
	while (m < n)
	{
		s1[m] = '\0';
		m++;
	}
	return (s1);
}

/**
  * _strcat - a function that concatenates 2 strings
  * @dest: string in which append takes place
  * @src: appended string
  * Return: pointer of the concatenated string
  */

char *_strcat(char *dest, char *src)
{
	int m = 0;
	int n = 0;

	for (; dest[m] != '\0')
		m++;
	for (; src[n] != '\0')
	{
		dest[m] = src[n];
		n++;
		m++;
	}
	dest[m] = '\0';
	return (dest);
}
