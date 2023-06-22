#include "monty.h"

/**
 * free_all - ...
 *
 * @stack: ...
 */
void free_all(stack_t **stack)
{
	stack_t *tmp_node;

	tmp_node = *stack;
	while (tmp_node != NULL)
	{
		tmp_node = (*stack)->prev;
		free(*stack);
		*stack = tmp_node;
	}

	fclose(global_vars.file);
}
