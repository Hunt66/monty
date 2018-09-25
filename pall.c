#include "stack.h"

/**
 *pall - prints all in stack
 *@head: head of the stack
 *Return: void
 */

void pall(stack_t **head)
{
	stack_t *current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
