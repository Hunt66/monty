#include"monty.h"

/**
 *rotr - rotates the bottom of the stack to the top
 *@stack: the head of the stack
 *@line_number: line number
 *Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->prev;
	current = current->prev;
	(*stack)->prev = NULL;
	current->next = NULL;
}
