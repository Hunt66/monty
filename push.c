#include "monty.h"


/**
 *push - pushes a number to the stack
 *@num: the number we are to push to the stack
 *@stack: the head of the list
 *Return: head of stack
 */

void push(int num, stack_t **stack)
{
	stack_t *new = NULL;

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
 */



void qu_push(int num, stack_t **stack)
{
	stack_t *new =  NULL;
	stack_t *current = NULL;

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
