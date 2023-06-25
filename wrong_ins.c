#include "monty.h"

/**
 * wrong_ins - prints error for wrong instruction and exits
 *
 * @line: line with error
 *
 * Return: void
 */

void wrong_ins(stack_t *h, unsigned int line)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, look[0]);
	free_mont(h);
	free_rd(look);
	exit(EXIT_FAILURE);
}
