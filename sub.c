#include "monty.h"


/**
 *sub - subtracts the top two elaments of the stack
 *@head: the head of the stack
 *@line: the line number
 *Return: void
 */

void sub(stack_t **head, unsigned int line)
{
	stack_t *next = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
		return;
	}

	next = *head;
	next = next->next;
	next->n = next->n - (*head)->n;
	free(*head);
	next->prev = NULL;
	*head = next;
}
