#include "monty.h"

/**
 *rotl - moves the top of the stack to the bottem
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number;
	if (*stack == NULL)
		return;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current = current->next;
	current->next = NULL;
}
