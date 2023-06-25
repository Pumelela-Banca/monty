#include "monty.h"

/**
 * main - entry point 
 *
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: always 0
 */

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	reader_line(argv);
	return (0);
}
