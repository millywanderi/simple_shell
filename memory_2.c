/*
 * File: memory_2.c
 * Auth: Justin Mwaipe, Millicent Wanderi
 */

#include "main.h"

/**
 * free_stat_mem - set head to NULL and free list
 * @head: pointer to list
 */

void free_stat_mem(memory_list **head)
{
	memory_list *temp;

	if (head)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->memory_ptr)
			free(temp->memory_ptr);
		free(temp);
	}
	*head = NULL;
}
