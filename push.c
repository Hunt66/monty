#include "stack.h"


/**
 *push - pushes a number to the stack
 *@num: the number we are to push to the stack
 *@head: the head of the list
 *Return: head of stack
 */

stack_t push(int num, stack_t **head)
{
	stack_t new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(10);
	new->n = num;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
		return (*head);
	}
	(*head)->prev = new;
	new->next = *head;
	*head = new;
	return (*head);
}
