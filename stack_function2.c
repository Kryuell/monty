#include "monty.h"

/**
* nofunction - Does nothing.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void nofunction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
* swap_nodes - Swaps the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		more_error(8, line_number, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
* add_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !(*stack) || !(*stack)->next)
		more_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* add_sub_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void add_sub_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (!stack || !(*stack) || !(*stack)->next)
		more_error(8, line_number, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
* add_div_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void add_div_nodes(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (!stack || !(*stack) || !(*stack)->next)
		more_error(8, line_number, "div");

	if ((*stack)->n == 0)
		more_error(9, line_number);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
