#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: start of list
 * @str: to add
 * @push_num: number to be pushed into stack
 *
 * Return: ptr to new head
 */

list_t *add_node_end(list_t **head, const char *str, int push_num)
{
	list_t *new;
	list_t *h;
	size_t i = 0;

	if (!head)
		return (NULL);
	h = *head;
	new = malloc(sizeof(list_t));
	if (!new)
	{
		free_list(*head);
		return (NULL);
	}

	new->str = strdup(str);
	while (str[i])
		i++;
	new->len = i;
	new->next = NULL;
	new->num = push_num;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (h->next)
		h = h->next;
	h->next = new;
	new->prev = h;
	return (*head);
}
