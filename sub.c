#include "monty.h"

/**
 * sub - subtracs the second element from the top of the list by 
 * the top element. The result is stored in the second 
 * element from the top and the top element is removed
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *go, *temp;

	go = temp = *stack;

	if (*stack == NULL || go->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_rd(look);
		exit(EXIT_FAILURE);
	}
	*stack = go->next;
	temp = temp->next;
	temp->n = temp->n - go->n;
	temp->prev = NULL;
	free(go);
}
