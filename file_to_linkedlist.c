#include "monty.h"
/**
 * file_to_linkedlist - takes a file name and makes a linked list
 *
 * @filename: path to file to open
 * Return: 0 if sucess else errcode
*/
int file_to_linkedlist(char *filename)
{
	FILE *mnty_fp;
	int op = 0;
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
		command = strtok(line_buff, "\t\n ");
		if (strcmp("push", command) == 0)
			num = strtok(NULL, "\t\n ");
		/* check for num is NAAN */
		if (num)
			op = atoi(num);
		else
			op = 0;
		add_node_end(&h, command, op);
	}
	free(line_buff);
	printf("---OUT OF GETLINE---\n");
	fclose(mnty_fp);
	return (0);
}
