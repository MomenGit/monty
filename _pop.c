#include "monty.h"

/**
 * pop - ...
 *
 * @stack: ...
 * @line_number: ...
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node;

	if (*stack != NULL)
	{
		tmp_node = *stack;

		*stack = (*stack)->prev;
		free(tmp_node);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
