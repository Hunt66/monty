#include"monty.h"

/**
 *mod - calcs the remainder of the second element of the stack by the first
 *@stack: the head of the stack
 *@line_number: line number
 *Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stack;
	current = current->next;
	current->n = current->n % (*stack)->n;
	free(*stack);
	current->prev = NULL;
	*stack = current;
}
