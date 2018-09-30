#include "monty.h"

/**
 * getfunc - function takes in a specifier in the form of a char
 * and returns the associated function to print an argument of that type
 *
 * @s: type char, the specifier passed in
 * @num: line number
 * Description: an array of structs is initialized with all possible specifiers
 * and the associated functions that will print arguments of that type
 *
 * Return: integer value, the number of characters printed when the called
 * function (via a function pointer) prints characters
*/

void (*getfunc(char *s, unsigned int line_number))(stack_t **stack,
						   unsigned int num)
{
	int i = 0;

	instruction_t arr[] = {
			{"push", push},
			{"pall", pall},
			{"pop", pop},
			{"pint", pint},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", _div},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{"pstr", pstr},
			{"rotl", rotl},
			{"rotr", rotr},
			{"stack", stack},
			{"queue", queue},
			{"#", comment},
			{'\0', NULL}
		};

	while (arr[i].opcode != '\0')
	{
		if (!strcmp(s, arr[i].opcode))
			return (arr[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, s);
	free_list(h);
	exit(EXIT_FAILURE);
}
