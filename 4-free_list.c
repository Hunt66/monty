#include "monty.h"
#include <stdlib.h>

/**
* free_list - clears a linked list from mem
* @head: ptr to head of linked list
*
* Return: nope void
*/

void free_list(list_t *head)
{
	list_t *new;

	while (head)
	{
		new = head;
		head = head->next;
		free(new->str);
		free(new);
	}
}
