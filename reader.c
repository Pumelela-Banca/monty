#include "monty.h"


/**
 * reader_line - opens file and reads the lines
 *
 * @argv: file to read
 *
 * Return: void
 */

void reader_line(char **argv)
{
	char buffer[256];
	int i = 1;
	unsigned int line = 1;
	stack_t *head = NULL;
	FILE *fd = fopen(argv[i], "r");
	instruction_t built[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", _div}, {"mul", mul}, {NULL, NULL}};

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 256, fd) != NULL)
	{
		if (buffer[0] == '\n' || buffer[0] == '#' ||
				jst_spaces(buffer) == 1)
		{
			line++;
			continue;
		}
		look = line_validity(&head, rm_ldspace(&head, buffer));
		i = 0;
		while (i < 11)
		{
			if (i == 10)
				wrong_ins(head, line);
			if (strcmp(look[0], built[i].opcode) == 0)
			{
				built[i].f(&head, line);
				break;
			}
			i++;
		}
		free_rd(look);
		line++;
	}
	free_mont(head);
	fclose(fd);
}


/**
 * jst_spaces - lines with just spaces
 *
 * @buff: buffer
 *
 * Return: 1 for true and 0 false
 */

int jst_spaces(char *buff)
{
	int i = 0;

	while (buff[i] == ' ')
	{
		if (buff[i] == '\n')
			return (1);
		else if (buff[i] != ' ')
			return (0);
		i++;
	}
	return (0);
}
/**
 * rm_ldspace - removes leading white spaces
 *
 * @buff: buffer
 * @stack: stack
 *
 * Return: array with new string
 */

char *rm_ldspace(stack_t **stack, char *buff)
{
	char *ld;
	int i = 0;

	ld = malloc(strlen(buff) * (sizeof(char)) + 1);
	if (ld == NULL)
	{
		free_rd(look);
		free_mont(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (buff[i] != '\n')
	{
		if (buff[i + 1] == '\n')
		{
			ld[i + 1] = ' ';
			ld[i + 2] = '\n';
		}
		ld[i] = buff[i];
		i++;
	}
	return (ld);
}

/**
 * line_validity - checks to see if line follows path
 *
 * @buf: line to cheak
 * @stack: list
 *
 * Return: start to end of command or NULL
 */

char **line_validity(stack_t **stack, char *buf)
{
	char **me;
	char *token;
	int count = 0;

	me = malloc(3 * sizeof(char *));
	if (me == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buf, " ");
	while (token != NULL || count < 2)
	{
		me[count] = malloc(strlen(token) + 1);
		if (me[count] == NULL)
		{
			free(me);
			free(me[count]);
			free_rd(look);
			free_mont(*stack);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(me[count], token);
		token = strtok(NULL, " ");
		count++;
	}
	free(buf);
	return (me);
}
