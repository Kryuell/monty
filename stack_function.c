#include "monty.h"


/**
* add_stack - Adds a node to the stack.
* @new_node: Pointer to the new node.
* @ln: Interger representing the line number of of the opcode.
*/
void add_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (!new_node || !(*new_node))
		exit(EXIT_FAILURE);

	if (!head)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
* print_stack - Adds a node to the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: line number of  the opcode.
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if (!stack)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* pop_top - Adds a node to the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack))
		more_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}
/**
* print_top_node - Prints the top node of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void print_top_node(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
		more_error(6, line_number);

	printf("%d\n", (*stack)->n);
}
