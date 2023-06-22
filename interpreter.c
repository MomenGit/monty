#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * interpret - ...
 */
void interpret(void)
{
	size_t line_n, i, inst_size;
	char buffer[MAX_LINE_LENGTH], *line;
	stack_t *stack_top;
	instruction_t instructions[] = INSTRUCTIONS;

	inst_size = 8;

	stack_top = NULL;

	for (line_n = 1;
		 (line = fgets(buffer, MAX_LINE_LENGTH, global_vars.file)) != NULL;
		 line_n++)
	{
		global_vars.op_code = strtok(buffer, " \n\t\t");
		global_vars.value = strtok(NULL, " \n\t\t");
		if (global_vars.op_code != NULL)
		{
			for (i = 0; i < inst_size; i++)
			{
				if (strcmp(global_vars.op_code, instructions[i].opcode) == 0)
				{
					if (instructions[i].f != NULL)
						instructions[i].f(&stack_top, line_n);
					break;
				}
			}
			if (i == inst_size)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
						line_n, global_vars.op_code);
				break;
			}
		}
		/*printf("%s %s\n", global_vars.op_code, global_vars.value);*/
	}
	free_all(&stack_top);
}
