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

int main (int argc, char *argv[])
{
	FILE *mnty_fp;
	unsigned int line_number = 0;
	int op = 0;
	size_t ln_bf_sz = 80;
	char *line_buff;
	char *command;
	char *num = NULL;
	const char s[2] = " ";
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
		return (0);
	}
	printf("opening %s\n", argv[1]);

	mnty_fp = fopen(argv[1], "r");
	if (mnty_fp == NULL)
		return (0);

	line_buff = malloc(ln_bf_sz * sizeof(char));

	while(-1 != getline(&line_buff, &ln_bf_sz, mnty_fp))
	{
	    ++line_number;
	    op = 0;
	    num = NULL;
		command = strtok(line_buff, s);
		if (strcmp("push", command) == 0)
			num = strtok(NULL, s);
		/* check for num is NAAN */
		if (num)	
			op = atoi(num);
		else
			op = 0;
		add_node_end(&h, command, op);
	}
	printf("---OUT OF GETLINE---\n");
	fclose(mnty_fp);
	print_list(h);
	fflush(stdout);
	while(h)
		getfunc(command)(&stack, line_number);
	return(0);

}
