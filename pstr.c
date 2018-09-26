#include"monty.h"

/**
 *pstr - prints the string starting at the start of the stack
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%c", current->n);
		current = current->next;
		if (current->n < 1 || current->n > 127)
			break;
	}
	printf("\n");
}
