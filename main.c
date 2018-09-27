#include "monty.h"
list_t *h = NULL;

/**
 * main - parses monty file and calls appropriate method
 *
 * @argc: argument count
 * @argv: argument array
 * Return: 0 if sucess else errcode
 * function (via a function pointer) prints characters
*/

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	list_t *current = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		free_all(&stack, 1);
		exit(EXIT_FAILURE);
		return (0);
	}
	printf("opening %s\n", argv[1]);


	file_to_linkedlist(argv[1]);

	print_list(h);
	fflush(stdout);
	current = h;
	while (current)
	{
	    line_number += 1;
		getfunc(current->str)(&stack, line_number);
		current = current->next;
	}
	free_all(&stack, line_number);
	return (0);
	
}
