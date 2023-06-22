#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>

#define INSTRUCTIONS        \
	{                       \
		{"add", add},       \
			{"nop", NULL},  \
			{"pall", pall}, \
			{"pint", pint}, \
			{"pop", pop},   \
			{"push", push}, \
			{"swap", swap}, \
		{                   \
			NULL, NULL      \
		}                   \
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_vars_s - struct used to contain global variables
 *
 * @file: the monty file pointer
 * @op_code: the current interpreted operation code
 * @value: the value of the current interpreted operation
 *
 * Description: struct used to contain global variables
 */
typedef struct global_vars_s
{
	FILE *file;
	char *op_code;
	char *value;
} global_vars_t;

void interpret(void);
void free_all(stack_t **stack);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

extern global_vars_t global_vars;
#endif
