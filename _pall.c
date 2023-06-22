#include "monty.h"

/**
 * pall - ...
 *
 * @stack:
 * @line_number:
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = *stack;
	if (line_number)
	{
	}
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}
