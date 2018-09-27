#include "monty.h"

/**
 *_div - divedes the second to top elament of the stack by the top elament
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stack;
	current = current->next;
	current->n = current->n / (*stack)->n;
	current->prev = NULL;
	free(*stack);
	*stack = current;
}
