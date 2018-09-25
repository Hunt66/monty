#include"monty.h"

/**
 *mod - calcs the remainder of the second element of the stack by the first
 *@head: the head of the stack
 *@line: line number
 *Return: void
 */

void mod(stack_t **head, unsigned int line)
{
	stack_t *current = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
		return;
	}

	current = *head;
	current = current->next;
	current->n = current->n % (*head)->n;
	free(*head);
	current->prev = NULL;
	*head = current;
}
