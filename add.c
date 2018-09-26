#include "monty.h"

/**
 *add - adds the top two elaments of the stack
 *@stack: head of stack
 *@line_number: line number
 *Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	next = *stack;
	next = next->next;
	next->n = next->n + (*stack)->n;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
