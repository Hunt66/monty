#include "stack.h"

int main(void)
{
	stack_t *head = NULL;
	push(0, &head);
	push(1, &head);
	push(2, &head);
	push(3, &head);
	pall(&head);
	return (0);
}
