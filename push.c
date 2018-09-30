#include "monty.h"


/**
 *push - pushes a number to the stack
 *@stack: the head of the list
 *@line_number: the line number
 *Return: head of stack
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int num;
	unsigned int i;
	list_t *current = NULL;
	stack_t *crnt = NULL;

	current = h;
	for (i = 1; i < line_number; i++)
		current = current->next;
	num = current->num;
	new = malloc(sizeof(stack_t));
	new->n = num;
	if (new == NULL)
	{
		free_all(stack, line_number);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
		return;
	}
	if (current->stk_q == 0)
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
	else
	{
		crnt = *stack;
		while (crnt->next != NULL)
			crnt = crnt->next;
		crnt->next = new;
		new->prev = crnt;
		new->next = NULL;
	}
}
