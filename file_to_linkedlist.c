#include "monty.h"
/**
 * file_to_linkedlist - takes a file name and makes a linked list
 *
 * @filename: path to file to open
 * Return: 0 if sucess else errcode
*/
int file_to_linkedlist(char *filename, stack_t *stack)
{
	FILE *mnty_fp;
	int op = 0;
	unsigned int line_number = 0;
	size_t ln_bf_sz = 80;
	char *line_buff;
	char *command;
	char *num = NULL;

	mnty_fp = fopen(filename, "r");
	if (mnty_fp == NULL)
		return (0);
	line_buff = malloc(ln_bf_sz * sizeof(char));
	while (-1 != getline(&line_buff, &ln_bf_sz, mnty_fp))
	{
		op = 0;
		num = NULL;
		line_number++;
		command = line_to_command(line_buff);
		if (strcmp("push", command) == 0)
		{
			num = strtok(NULL, " \n");
			for (op = 0; num[op] != '\0'; op++)
			{
				if (num[op] == '-' && op == 0 && num[op+1])
					continue;
				if (num[op] > '9' || num[op] < '0' || num[op] ==
					'+' || num[op] == '-')
				{
					fprintf(stderr,
						"L%d: usage: push integer\n",
						line_number);
					free(line_buff);
					fclose(mnty_fp);
					free_all(&stack, 1);
					exit(EXIT_FAILURE);
				}
			}
		}
		if (num)
			op = atoi(num);
		else
			op = 0;
		add_node_end(&h, command, op);
	}
	fclose(mnty_fp);
	free(line_buff);
	return (0);
}

/**
 * line_to_command - takes a file name and makes a linked list
 *
 * @line_buff: line to turn to a command
 * Return: 0 if sucess else errcode
*/

char *line_to_command(char *line_buff)
{
		char *command;
		int op = 0;

		while (line_buff[op] != '\n')
		{
			if (line_buff[op] != ' ')
				break;
			op++;
		}
		if (line_buff[op] != '\n')
		{
			command = strtok(line_buff, " \n");
		}
		else
			command = "BLANK";
		return (command);
}
