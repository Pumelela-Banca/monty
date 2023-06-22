#include "main.h"

/**
 * free_rd - frees line cheacker
 *
 * @me: array
 *
 * Return: void
 */

void free_rd(char **me)
{
	int i;

	for (i = 0; i < 2; i++)
		free(me[i]);
	free(me);
}
