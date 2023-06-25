#include "monty.h"

/**
 * add - adds the top two elements and deletes the top most
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *go, *temp;

	go = temp = *stack;
	if (*stack == NULL || go->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_rd(look);
		free_mont(go);
		exit(EXIT_FAILURE);
	}
	*stack = go->next;
	temp = temp->next;
	temp->n += go->n;
	temp->prev = NULL;
	free(go);
}
