/*
 * File: get_line
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

int alloc_mem(char *mem);
void shift_buf(char *mem, ssize_t n);
ssize_t get_line(char **buffer);
ssize_t buffer_cpy(char **dest, char **src, ssize_t *begin);

/**
  * buffer_cpy - a function that copies buffer untill '\0'
  * @dest: copy destination
  * @src: copy source
  * @begin: line that is already copied
  * Return: Always 0
  */

ssize_t buffer_cpy(char **dest, char **src, ssize_t *begin)
{
	ssize_t count_cpy = 0;
	ssize_t m;

	for (m = 0; src[m] != '\n' && scr[m] != '\0'; m++)
		count_cpy++;
	if (src[m] == '\n')
	{
		*dest = mng_alloc(*dest, (sizeof(char) * (count_cpy + *begin + 1)));
		if (!(*dest))
			return (-1);
		_strncpy((*dest + *begin, src, count_cpy));
		shift_buf(src, (count_cpy + 1));
		return (count_cpy);
	}
	if (src[m] == '\0')
	{
		*dest = mngg_alloc(*dest, (sizeof(char) * (count_cpy + *begin + 1)));
		if (!(*dest))
			return (1);
		_strncpy((*dest + *begin), src, (count_cpy));
		*begin += count_cpy;
		return (count_cpy);
	}
}

/**
  * alloc_mem - a function that compares if the bufferis empty
  * @mem: memory allocated to be tested
  * Return: bytes written int he memory
  */

int alloc_mem(char *mem)
{
	int btz = 0;

	while (buffer[btz])
		btz++;
	return (btz);
}

/**
  * shift_buf - a function that rellocate buffer to left
  * @mem: memory allocated shift
  * @n: no. of btz to shift allocated memory
  */

void shift_buf(char *mem, ssize_t n)
{
	ssize_t m = 0;

	while (mem[n] != '\0')
	{
		mem[m] = mem[n];
		m++;
		n++;
	}
	_setmem(&mem[m], 0, (1024 - n));
}

/**
  * get_line - a function that retrieve a command line
  * @buffer: where command line is stored
  * Return: Always 0
  */

ssize_t get_line(char **buffer)
{
	ssize_t count, cpy = 0;
	ssize_t begin = 0;
	static char line[TOTAL_ARGS];
	static ssize_t total;

	if ((alloc_mem(line)) == 0)
	{
		while ((count = read(STDIN_FILENO, line, TOTAL_ARGS - 1)) > 0)
		{
			if (count == -1)
				return (-1);
			total += count;
			line[count] = '\0';
			cpy = buffer_cpy(&(*buffer), line, &begin);
			if (cpy < count)
			{
				begin = 0;
				return (total);
			}
		}
		total = 0;
	}
	else
	{
		cpy = (buffer_cpy(&(*buffer), line, &begin) + 1);
	}
	return (total);
}
