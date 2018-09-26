#include"monty.h"

/**
 *mul - multiplies the top two elaments of the stack
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stack;
	current = current->next;
	current->n = current->n * (*stack)->n;
	free(*stack);
	current->prev = NULL;
	*stack = current;
}
