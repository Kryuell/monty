#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
* print_char - Prints the Ascii value.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (!stack || !(*stack))
	{
		string_error(11, line_number);
		return;
	}

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
	{
		string_error(10, line_number);
		return;
	}

	printf("%c\n", ascii);
}
/**
* print_string - Prints a string.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @ln: Interger representing the line number of of the opcode.
*/
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;

	stack_t *tmp;

	if (!stack || !(*stack))
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
		{
			break;
		}
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
* rotl - Rotates the first node of the stack to the bottom.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @ln: Interger representing the line number of of the opcode.
*/
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		return;
	}

	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
* rotr - Rotates the last node of the stack to the top.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @ln: Interger representing the line number of of the opcode.
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		return;
	}

	tmp = *stack;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
