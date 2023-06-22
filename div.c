#include "monty.h"

/**
 * _div - divides top two elements and the top is removed and the 
 * result stored in second most element
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: Void
 */

void _div(stack_t **stack, unsigned int line_number)
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
	if (go->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		free_rd(look);
		free(go);
		exit(EXIT_FAILURE);
	}
        temp->n /= go->n;
        temp->prev = NULL;
        free(go);
}
