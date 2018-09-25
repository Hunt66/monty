#include"monty.h"

/**
 *mul - multiplies the top two elaments of the stack
 *@head: the head of the stack
 *@line: the line number
 *Return: void
 */

void mul(stack_t **head, unsigned int line)
{
	stack_t *current = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mul, stack too short", line);
		exit(EXIT_FAILURE);
		return;
	}

	current = *head;
	current = current->next;
	current->n = current->n * (*head)->n;
	free(*head);
	current->prev = NULL;
	*head = current;
}