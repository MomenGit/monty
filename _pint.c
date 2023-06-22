#include "monty.h"

/**
 * pint - ...
 *
 * @stack: ...
 * @line_number: ...
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
}
