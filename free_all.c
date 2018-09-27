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

	if (h)
	{
		while (h != NULL)
		{
			h = h->next;
			free(crnt->str);
			free(crnt);
			crnt = h;
		}
	}

	current = *stack;
	if (*stack)
	{
		while (*stack != NULL)
		{
			*stack = (*stack)->next;
			free(current);
			current = *stack;
		}
	}

}
