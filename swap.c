#include "main.h"

/**
 * swap - swaps top two elements
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *go, *temp;

	go = temp = *stack;
	if (*stack == NULL || go->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		free_rd(look);
		exit(EXIT_FAILURE);
	}
	*stack = go->next;
	temp = temp->next;
	temp->prev = NULL;
	go->next = temp->next;
	go->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = temp;
}
