#include "monty.h"

/**
 *pchar - prints the ascii interpratation of the top stack number
 *@stack: the head of the stack
 *@line_number: line number
 *Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	printf("%c\n", (*stack)->n);
}
