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
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	list_t *current = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_all(&stack, 1);
		exit(EXIT_FAILURE);
		return (0);
	}

	if (access(argv[1], F_OK | X_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file_to_linkedlist(argv[1], stack);

	fflush(stdout);
	for (current = h; current; line_number++)
	{
		if (strcmp("BLANK", current->str) != 0)
			getfunc(current->str)(&stack, line_number);
		current = current->next;
	}
	if (stack)
		free_all(&stack, 1);
	return (0);
}
