#include "monty.h"

/**
 * swap - ...
 *
 * @stack: ...
 * @line_number: ...
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node;

	if (*stack != NULL)
	{
		if ((*stack)->prev != NULL)
		{
			tmp_node = *stack;
			(*stack) = (*stack)->prev;
			tmp_node->prev = (*stack)->prev;
			(*stack)->prev = tmp_node;
			return;
		}
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_all(stack);
	exit(EXIT_FAILURE);
}
