#include "stack.h"

int main(void)
{
	stack_t *head = NULL;
	push(0, &head);
	push(1, &head);
	push(2, &head);
	push(3, &head);
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
