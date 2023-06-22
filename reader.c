#include "main.h"


/**
 * reader_line - opens file and reads the lines
 *
 * @file: file to read
 *
 * Return: void
 */

void reader_line(char **argv)
{
	char buffer[256];
	char *ld;
	int i = 1;
	unsigned int line = 1;
	stack_t *head = NULL;
	FILE *fd = fopen(argv[i], "r");
	instruction_t built[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", _div}, {"mul", mul}, {NULL, NULL}};

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/*Read file*/
	while (fgets(buffer, 256, fd) != NULL)
	{
		if (buffer[0] == '\n' || buffer[0] == '#')
			continue;
		ld = rm_ldspace(buffer);
		look = line_validity(ld);
		free(ld);
		i = 0;
		while (built[i].opcode != NULL)
		{
			if (strcmp(look[0], built[i].opcode) == 0)
				built[i].f(&head, line);
		}
		free_rd(look);
		line++;
	}
}
/**
 * rm_ldspace - removes leading white spaces
 *
 * @buff: buffer
 *
 * Return: array with new string
 */

char *rm_ldspace(char *buff)
{
	char *ld;
	int i = 0;

	ld = malloc(strlen(buff) * (sizeof(char )) + 1);
	if (ld == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
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
 * @line: line to cheak
 *
 * Return: start to end of command or NULL
 */

char **line_validity(char *buf)
{
	char **me;
	char *token;
	int count = 0;

	me = malloc(3 * sizeof(char *));
	if (me == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(buf, " ");
	while (token != NULL || count < 3)
	{
		me[count] = malloc(strlen(token) + 1);
		if (me[count] == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(me[count], token);
		token = strtok(NULL, " ");
		count++;
	}
	return (me);
}
