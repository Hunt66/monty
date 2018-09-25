#include "monty.h"

/**
 *add - adds the top two elaments of the stack
 *@head: head of stack
 *@line: line number
 *Return: void
 */

void add(stack_t **head, unsigned int line)
{
	stack_t *next = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
		return;
	}

	next = *head;
	next = next->next;
	next->n = next->n + (*head)->n;
	free(*head);
	next->prev = NULL;
	*head = next;
}
