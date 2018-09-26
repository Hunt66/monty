#include"monty.h"


int main(void)
{
	stack_t *head;

	push(0, &head);
	push(1, &head);
	push(2, &head);
	push(3, &head);
	pall(&head, 1);
	rotr(&head, 1);
	pall(&head, 1);
}
