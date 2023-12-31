#include "monty.h"

/**
 * pint - print top element on stack
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *go;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_rd(look);
		free_mont(*stack);
		exit(EXIT_FAILURE);
	}
	go = *stack;
	printf("%d\n", go->n);
}
