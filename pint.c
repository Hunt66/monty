#include "monty.h"

/**
 *pint - prints the value at the top of the stack
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*stack)->n);
}
