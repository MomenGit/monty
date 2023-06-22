#include "monty.h"

global_vars_t global_vars = {NULL, NULL, NULL};

/**
 * main - program entry point
 *
 * @argc: arguments count
 * @argv: arguments array
 * Return: int
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_vars.file = fopen(argv[1], "r");
	if (global_vars.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	interpret();
	return (0);
}
