#include "monty.h"

/**
 * push - ...
 *
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if ((new_node->n = atoi(global_vars.value)) == 0 && strcmp(global_vars.value, "0"))
	{
		fprintf(stderr, "L%d: usage push n\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;

	if (*stack != NULL)
	{
		while ((*stack)->next != NULL)
			(*stack) = (*stack)->next;
		new_node->prev = *stack;
		(*stack)->next = new_node;
	}
	else
	{
		new_node->prev = NULL;
	}
	*stack = new_node;
}
