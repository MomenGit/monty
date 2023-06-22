#include "monty.h"

/**
 * add - ...
 *
 * @stack: ...
 * @line_number: ...
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node;

	if (*stack != NULL)
	{
		if ((*stack)->prev != NULL)
		{
			tmp_node = *stack;
			(*stack) = (*stack)->prev;
			(*stack)->n += tmp_node->n;
			free(tmp_node);
			return;
		}
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_all(stack);
	exit(EXIT_FAILURE);
}
