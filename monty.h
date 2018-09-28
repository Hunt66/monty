#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - singly linked list
 * @str: instruction code - (malloc'ed string)
 * @len: length of the string
 * @num: line number in file for errors handling
 * @next: points to the next node
 * @prev: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	int num;
	struct list_s *next;
	struct list_s *prev;
} list_t;

extern list_t *h;

void push(stack_t **stack, unsigned int num);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

char *line_to_command(char *line_buff);
char *token_check(char *num);

int file_to_linkedlist(char *filename, stack_t *stack);


void (*getfunc(char *s, unsigned int line_number))(stack_t **stack,
                           unsigned int line_number);



void free_all(stack_t **stack, unsigned int line_number);


int _putchar(char c);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);

list_t *add_node_end(list_t **head, const char *str, int opcode);
void free_list(list_t *head);

#endif/*MONTY_H*/
