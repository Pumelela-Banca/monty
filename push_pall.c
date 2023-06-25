#include "monty.h"

/**
 * push - push element to stack
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;
	int n;

	if (look[1][0] == '\n' || !(look[1][0] == '-' ||
			(look[1][0] > 47 && look[1][0] < 58)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_rd(look);
		free_mont(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_mont(new);
		free_rd(look);
		exit(EXIT_FAILURE);
	}
	n = find_int(new, line_number);
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		new->n = n;
		*stack = new;
	}
	else
	{
		temp = *stack;
		new->next = *stack;
		new->prev = NULL;
		temp->prev = new;
		new->n = n;
		*stack = new;
	}
}

/**
 * pall - print all elements in linked list
 *
 * @stack: structure for list
 * @line_number: line with command
 *
 * Return: void
 *
 */

void pall(stack_t **stack,
		unsigned int line_number)
{
	stack_t *go;

	if (*stack == NULL)
		return;
	line_number++;
	go = *stack;
	while (go != NULL)
	{
		printf("%d\n", go->n);
		go = go->next;
	}
}


/**
 * find_int - converts string to integer
 *
 * @line_number: line of command
 * @stack: structure
 *
 * Return: integer
 */

int find_int(stack_t *stack, unsigned int line_number)
{
	int l, sign, count = 0, len;
	char num[6];

	if (look[1][0] == '-')
		sign = 1;
	else
		sign = 0;
	len = strlen(look[1]) - sign;
	for (l = sign; l < len; l++)
	{
		if (look[1][l] > 47 && look[1][l] < 58)
		{
			num[count] = look[1][l];
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_rd(look);
			free(stack);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	if (sign == 1 && atoi(num) != 0)
		return (-1 * atoi(num));
	else
		return (atoi(num));
}
