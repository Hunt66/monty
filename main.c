#include "monty.h"



/**
 * getfunc - function takes in a specifier in the form of a char
 * and returns the associated function to print an argument of that type
 *
 * @s: type char, the specifier passed in
 *
 * Description: an array of structs is initialized with all possible specifiers
 * and the associated functions that will print arguments of that type
 *
 * Return: integer value, the number of characters printed when the called
 * function (via a function pointer) prints characters
*/

void (*getfunc(char *s))
(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t arr[] = {
			{"push", push},
			{"pall", pall},
			// {"pop", pop},
			// {"swap", swap},
			// {"add", add},
			// {"nop", nop},
			// {"sub", sub},
			// {"div", div},
			// {"mul", mul},
			// {"mod", mod},
			// {"pchar", pchar},
			// {"pstr", pstr},
			// {"rotl", rotl},
			// {"rotr", rotr},
			// {"stack", stack},
			// {"queue", queue},
			{'\0', NULL}
		};


	while (arr[i].opcode != '\0')
	{
		if (!strcmp(s, arr[i].opcode))
			return (arr[i].f);
		i++;
	}
	// return (_negativeone);
	return(NULL);
}

list_t *h = NULL;

int main (int argc, char *argv[])
{
	FILE *mnty_fp;
	unsigned int line_number = 0;
	int op = 0;
	size_t ln_bf_sz = 80;
	char *line_buff;
	char *command;
	char *opcode = NULL;
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

	// read each line and print it to the screen
	while(-1 != getline(&line_buff, &ln_bf_sz, mnty_fp))
	{
	    ++line_number;
	    op = 0;
	    opcode = NULL;
		/* get the first token */
		command = strtok(line_buff, s);
		if (strcmp("push", command) == 0)
			opcode = strtok(NULL, s);
		if (opcode)
		{
			while(opcode[op]){
				if (opcode[op++] > 80 || opcode[op] > 89)
				{
					printf("%s ---NAAN--- not a number\n", opcode);
					return(0);
				}
			}		
			op = atoi(opcode);
		}
		else
			op = -1;
		add_node_end(&h, command, op);
		getfunc(command)(&stack, line_number);
	}
	printf("---OUT OF GETLINE---\n");
	// close(mnty_fp);
	print_list(h);
	fflush(stdout);
	return(0);

}
