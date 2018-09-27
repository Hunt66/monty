#include "monty.h"


/**
 *push - pushes a number to the stack
 *@num: the number we are to push to the stack
 *@stack: the head of the list
 *Return: head of stack
 */


void push(stack_t **stack, unsigned int num)
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
