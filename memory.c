/*
 * File: memory.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * mng_alloc - create and allocate memory space
 * @size: Size of allocation
 * @ptr: Pointer to memory
 *
 * Return: NULL on failure, pointer on Success
 */

char *mng_alloc(char *ptr, size_t size)
{
	ptr = re_alloc(ptr, size);
	if (!(ptr))
	{
		perror("hsh");
		free_mem(&memory_head);
		return (NULL);
	}

	memory_head = add_memory(&memory_head, ptr);
	return (ptr);
}

/**
 * re_alloc - add reallocates memory
 * @ptr: Old pointer to memory
 * @new_allocsize: Size of new alloc
 *
 * Return: Pointer to new alloc list on success, old on fail
 */

char *re_alloc(char *ptr, size_t new_allocsize)
{
	size_t oldsize = _strlen(ptr);
	size_t m = 0;
	char *realloc_ptr;

	if (new_allocsize == oldsize)
		return (ptr);
	if (new_allocsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	realloc_ptr = malloc(new_allocsize);
	if (!realloc_ptr)
		return (NULL);
	if (ptr)
	{
		for (m = 0; m < oldsize && m < new_allocsize; m++)
			*(realloc_ptr + m) = *(ptr + m);

		free(ptr);
	}

	_setmem((realloc_ptr + oldsize), 0, (new_allocsize - oldsize));
	return (realloc_ptr);
}

/**
 * free_mem - Free memory and set head to NULL
 * @head: pointer to free
 */

void free_mem(memory_list **head)
{
	memory_list *temp;

	if (head)
	{
		while (*head)
		{
			temp = *head;
			*head = (*head)->next;
			if (temp->memory_ptr)
				free(temp->memory_ptr);
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_memory - add node memory to beginning of list
 * @ptr: Old pointer to memory
 * @head: new head of list
 *
 * Return: Pointer to new alloc list
 */

memory_list *add_memory(memory_list **head, char *ptr)
{
	memory_list *new_node;

	new_node = malloc(sizeof(memory_list));
	if (!new_node)
		return (NULL);

	new_node->memory_ptr = ptr;
	new_node->next = *head;
	*head = new;

	return (*head);
}

/**
 * _setmem - Memory with constant byte
 * @m: memory area to fill
 * @j: constant byte
 * @d: bytes to fill
 *
 * Return: pointer to memory area
 */

char *_setmem(char *m, char j, unsigned int d)
{
	unsigned int t = 0;

	while (t < n)
	{
		m[t] = j;
		t++;
	}
	return (m);
}
