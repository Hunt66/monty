#include "monty.h"
#include "lists.h"

int main (int argc, char *argv[])
{
	FILE *monty_file_pointer;
	int line_number = 0, op;
	size_t line_buff_size = 80;
	char *line_buff;
	char *opcode;
	char *command;
	const char s[2] = " ";
	list_t *h;


	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
		return (0);
	}
	printf("opening %s\n", argv[1]);

	monty_file_pointer = fopen(argv[1], "r");
	if (monty_file_pointer == NULL)
		return (0);

	line_buff = malloc(line_buff_size * sizeof(char));

	// read each line and print it to the screen
	while(-1 != getline(&line_buff, &line_buff_size, monty_file_pointer))
	{
	    printf("%d: %s", ++line_number, line_buff);

		/* get the first token */
		command = strtok(line_buff, s);
		opcode = strtok(NULL, s);
		if (!(command && opcode))
		{
			command = "blank";
			opcode = "-1";
		}
		printf( "command: %s\nopcode: %s\n", command, opcode );
		op = atoi(opcode);
		add_node_end(&h, command, op);
	}
	printf("\n");
	print_list(h);
	fflush(stdout);

}


