#include "monty.h"

int main(void)
{
	stack_t *head = NULL;
	push(0, &head);
	push(1, &head);
	push(2, &head);
	push(14, &head);
	push(-4, &head);
	push(-5, &head);
	push(-6, &head);
	printf("pushed\n");
	pall(&head);
	swap(&head, 1);
	printf("swapped\n");
	pall(&head);
	add(&head, 1);
	printf("added\n");
	pall(&head);
	sub(&head, 1);
	nop();
	printf("subbed and nop\n");
	pall(&head);
	_div(&head, 1);
	printf("divided\n");
	pall(&head);
	mul(&head, 1);
	printf("multiplied\n");
	pall(&head);
	mod(&head, 1);
	printf("modded\n");
	pall(&head);
	pint(&head, 1);
	pop(&head, 1);
        pint(&head, 1);
        pop(&head, 1);
        pint(&head, 1);
	printf("test 1\n");
        pop(&head, 1);
	printf("test 2\n");
        pint(&head, 1);
	printf("test 3\n");
        pop(&head, 1);
	printf("test 4\n");

	printf("test 5\n");
        pop(&head, 1);
	printf("test 6\n");
	pint(&head, 1);
	printf("test 7\n");
	return (0);
}
