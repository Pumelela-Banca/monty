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


	if (look[1][0] == '\n' || !(look[1][0] > 47 && look[1][0] < 58)
			|| look[1][0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer JJJJ\n", line_number);
		free_rd(look);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_rd(look);
		exit(EXIT_FAILURE);
	}
	n = find_int(line_number);
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

void pall(stack_t **stack, unsigned int __attribute__((__unused__)) line_number)
{
	stack_t *go;

	if (*stack == NULL)
		return;
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
 *
 * Returns: integer
 */

int find_int(unsigned int line_number)
{
	int l, sign, count = 0;
	char num[5];

	if (look[1][0] == '-')
		sign = 1;
	else
		sign = 0;
	for (l = sign; look[1][l] != '\0'; l++)
	{
		if (look[1][0] > 47 && look[1][0] < 58)
			num[count] = look[1][l];
		else if (!(look[1][0] > 47 && look[1][0] < 58))
		{
			printf("jJJJJJ\n");
			fprintf(stderr, "L%d: usage: push integer TEST\n", line_number);
			free_rd(look);
			exit(EXIT_FAILURE);
		}
	}
	if (sign == 1)
		return (-1 * atoi(num));
	else
		return (atoi(num));
}
