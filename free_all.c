#include "monty.h"

/**
 *free_all - frees all lists and closes all files if nessisary
 *@stack: the head of the stack to free
 *@line_number: the line number
 *Return: void
 */

void free_all(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	list_t *crnt = NULL;

	(void)line_number;
	crnt = h;
	while (h != NULL)
	{
		h = h->next;
		free(crnt);
		crnt = h;
	}

	if (*stack == NULL)
		return;

	current = *stack;
	while (*stack != NULL)
	{
		*stack = (*stack)->next;
		free(current);
		current = *stack;
	}

	/*freeing line list goes here possibley */
}
