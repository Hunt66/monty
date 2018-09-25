#include "monty.h"

/**
 *pint - prints the value at the top of the stack
 *@head: the head of the stack
 *Return: void
 */

void pint(stack_t **head, int line)
{
	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*head)->n);
}
