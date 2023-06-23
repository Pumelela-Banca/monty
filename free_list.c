#include "monty.h"

/**
 * free_mont - free memory from list
 *
 * @head: start of list
 *
 * Return: void
 */

void free_mont(stack_t *head)
{
	stack_t *go, *temp;

	go = head;
	while (go != NULL)
	{
		temp = go->next;
		free(go);
		go = temp;
	}
}
