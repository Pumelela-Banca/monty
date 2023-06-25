#include "monty.h"

/**
 * pop - removes top element of struct
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *go;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_rd(look);
		free_mont(*stack);
		exit(EXIT_FAILURE);
	}
	go = *stack;
	if (go->next == NULL)
		*stack = NULL;
	else
	{
		go->next->prev = NULL;
		*stack = go->next;
	}
	free(go);
}
