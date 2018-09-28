#include "monty.h"

/**
 *pop - removes the top of the stack
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}
	current = *stack;
	if (current->next == NULL)
	{
		free(current);
		*stack = NULL;
	}
	else
	{
		*stack = current->next;
		free(current);
		(*stack)->prev = NULL;
	}

}
