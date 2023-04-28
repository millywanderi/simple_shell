/*
 * Auth: Justin Mwaipe, Millicent Wanderi
 * File: function.c
 */

#include "main.h"

char *_revstr(char *str);
char *_strcat(char *dest, const char *src);
char *_strncpy(char *s1, const char *s2, size_t n);

/**
  * _revstr - a function that reverses a string
  * @str: string to be reversed
  * Return: reversed string
  */

char *_revstr(char *str)
{
	int l = 0;
	int r = 0;
	int len = 0;
	int size = 0;
	char mem;

	len = _strlen(str);

	if ((len % 2) == 0)
	{
		size = (len / 2);
	}
	else
		size = (len - 1) / 2;

	r = len - 1;
	while (l < size && r >= size)
	{
		mem = str[l];
		str[l] = str[r];
		str[r] = mem;
		l++;
		r--;
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

char *_strncpy(char *s1, const char *s2, size_t n)
{
	size_t m = 0;

	while (m < n && s2[m] != '\0')
	{
		s1[m] = s2[m];
		m++;
	}
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

char *_strcat(char *dest, const char *src)
{
	int m = 0;
	int n;

	while (dest[m] != '\0')
	{
		m++;
	}
	for (n = 0; src[n] != '\0')
	{
		dest[m] = src[n];
		n++;
		m++;
	}
	dest[m] = '\0';
	return (dest);
}
