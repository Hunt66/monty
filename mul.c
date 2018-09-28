#include"monty.h"

/**
 *mul - multiplies the top two elaments of the stck
 *@stck: the head of the stack
 *@line_number: the line number
 *Return: void
 */

void mul(stack_t **stck, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stck == NULL || (*stck)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(stck, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stck;
	current = current->next;
	current->n = current->n * (*stck)->n;
	free(*stck);
	current->prev = NULL;
	*stck = current;
}
