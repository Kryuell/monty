#include "monty.h"

/**
* add_mul_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void add_mul_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* add_mod_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void add_mod_nodes(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (!stack || !(*stack) || !(*stack)->next)
		more_err(8, line_number, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_number);

	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
