#include "monty.h"


/**
 *push - pushes a number to the stack
 *@num: the number we are to push to the stack
 *@stack: the head of the list
 *@line_number: the line number
 *Return: head of stack
 */

void push(stack_t **stack, unsigned int num)
{
	stack_t *new = NULL;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(10);
	new->n = num;

	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
		return;
	}
	(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}

/**
 *qu_push: pushes code to the bottom of the stack (used while in queue mode)
 *@num: the number to add to the queue
 *@stack: the head of the stack
 *@line_number: the line number
 */



void qu_push(int num, stack_t **stack, unsigned int line_number)
{
	stack_t *new =  NULL;
	stack_t *current = NULL;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(10);
	new->n = num;

	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
		return;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	new->prev = current;
}
