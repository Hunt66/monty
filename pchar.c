#include "monty.h"

/**
 *pchar - prints the ascii interpratation of the top stack number
 *@head: the head of the stack
 *@line: line number
 *Return: void
 */

void pchar(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
		return;
	}

	printf("%c\n", (*head)->n);
}