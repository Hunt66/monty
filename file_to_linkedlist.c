#include "monty.h"
/**
 * file_to_linkedlist - takes a file name and makes a linked list
 *
 * @filename: path to file to open
 * @stack: there in case of err for free
 * Return: 0 if success else errcode
*/
void file_to_linkedlist(char *filename, stack_t *stack)
{
	FILE *mnty_fp;
	int op = 0;
	unsigned int line_number = 0;
	size_t ln_bf_sz = 80;
	char *line_buff, *command, *num = NULL;

	mnty_fp = fopen(filename, "r");
	if (mnty_fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
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
			num = token_check(num);
			if (num == NULL)
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
		if (num)
			op = atoi(num);
		add_node_end(&h, command, op);
	}
	fclose(mnty_fp);
	free(line_buff);
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

		if (line_buff[0] == '#')
			return ("#");

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
			return ("BLANK");
		return (command);
}

/**
 * token_check - checks our token for int-ynesss
 *
 * @num: token to check
 * Return: 0 if sucess else errcode
*/

char *token_check(char *num)
{
	int i = 0;

	if (num == NULL)
		return (NULL);

	for (i = 0; num[i] != '\0'; i++)
	{
		if (i == 0 && num[0] == '-' && num[1])
			continue;
		if (num[i] > '9' || num[i] < '0')
			return (NULL);
	}
	return (num);
}
