#include "monty.h"


/**
 *sub - subtracts the top two elaments of the stack
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	next = *stack;
	next = next->next;
	next->n = next->n - (*stack)->n;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
