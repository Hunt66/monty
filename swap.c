#include "monty.h"

/**
 *swap - swaps the first two lines of the stack
 *@head: the head of the stack
 *@line: the line number
 *Return: void
 */

void swap(stack_t **head, unsigned int line)
{
	stack_t *current = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
		return;
	}

	current = *head;
	current = current->next;
	(*head)->next = current->next;
	current->next = *head;
	current->prev = NULL;
	(*head)->prev = current;
	current->prev = NULL;
	*head = current;
}
