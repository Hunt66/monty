#include "monty.h"

/**
 *swap - swaps the first two lines of the stack
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stack;
	current = current->next;
	(*stack)->next = current->next;
	current->next = *stack;
	current->prev = NULL;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}
