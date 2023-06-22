#include "monty.h"

/**
 * mul - multiplies top two elements and the top is removed and the
 * product stored in second most element
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void mul(stack_t **stack, unsigned int line_number)
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
	temp->n *= go->n;
	temp->prev = NULL;
	free(go);
}
