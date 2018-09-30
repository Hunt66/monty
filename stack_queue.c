#include "monty.h"

/**
 * stack - switches the push order to stack
 *@stack: the head of the stack
 *@line_number: line number
 *Return: void
 */

void stack(stack_t **stack, unsigned int line_number)
{
	list_t *current = NULL;

	(void) stack;
	(void) line_number;

	current = h;
	while (current != NULL)
	{
		current->stk_q = 0;
		current = current->next;
	}
}




/**
 *queue - switches the push order to queue mode
 *@stack: the head of the stack
 *@line_number: the line number
 *Return: void
 */


void queue(stack_t **stack, unsigned int line_number)
{
	list_t *current = NULL;

        (void) stack;
        (void) line_number;

        current = h;
        while (current != NULL)
        {
                current->stk_q = 1;
                current = current->next;
        }
}
