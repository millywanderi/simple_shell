/*
 * Auth: Justin Mwaipe, Millicent Wanderi
 * File: cd.c
 */

#include "main.h"
/**
  * cdir - a function that changes a directory
  */

int cdir()
{
	char *m, *directory, *way;
	char buffer[BUFFER_SIZE];
	int checkdir, x = 1;

	m = getcwd(buffer, 1024);
	if (m == NULL)
	{
		perror("Error ");
		return (-2);
	}
	if (!infor->argv[1])
	{
		directory = getenv(infor, "HOME");
		if (!directory)
			directory = getenv(infor, "HOME");
	}
	else if (strcmp(infor->argv[1], "-") == 0)
	{
		if (!getenv(infor, "OLDPWD"))
		{
			puts(m);
			printf("\n");
			return (0);
		}
	}
	else
	{
		way = malloc(sizeof(char) * 1024);
		if (!way)
			return (-1);
		way[0] = '\0';
		while(infor->argv[x])
		{
			strcat(way, infor->argv[x]);
			if (infor->argv[x + 1])
				strcat(way, " ");
			x++;
		}
		directory = way;
	}
	checkdir = chdir(directory);
	if (checkdir == -1)
	{
		perror("Error ");
		free(way);
		return (-1);
	}
	free(way);
	if (setenv(infor, "OLDPWD", m) == -1)
		return (-1);
	if (setenv(infor, "PWD", getcwd(buffer, 1024)) == -1)
		return (-1);
	return (0);
}
