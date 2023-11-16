#ifndef MONTY
#define MONTY
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stddef.h>
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

#define INSTRUCTIONS { \
		{"push", _push},\
		{"pall", _pall},\
		{"pint", _pint},\
		{"pop", _pop},\
		{"swap", _swap},\
		{"nop", _nop},\
		{"div", _div},\
		{"mul", _mul},\
		{"add", _add},\
		{"sub", _sub},\
		{"mod", _mod},\
		{"pchar", _pchar},\
		{"pstr", _pstr},\
		{"rotl", _rotl},\
		{"rotr", _rotr},\
		{NULL, NULL} \
	}
/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

extern int status;

void _push(stack_t **stack, unsigned int line_cnt);
void _pall(stack_t **stack, unsigned int line_cnt);
void _pint(stack_t **stack, unsigned int line_cnt);
void _swap(stack_t **stack, unsigned int line_cnt);
void _pop(stack_t **stack, unsigned int line_cnt);
void _nop(stack_t **stack, unsigned int line_cnt);
void _div(stack_t **stack, unsigned int line_cnt);
void _add(stack_t **stack, unsigned int line_cnt);
void _sub(stack_t **stack, unsigned int line_cnt);
void _mul(stack_t **stack, unsigned int line_cnt);
void _mod(stack_t **stack, unsigned int line_cnt);
void _pchar(stack_t **stack, unsigned int line_cnt);
void _pstr(stack_t **stack, unsigned int line_cnt);
void _rotl(stack_t **stack, unsigned int line_count);
void _rotr(stack_t **stack, unsigned int line_count);
void _opcode(stack_t **stack, char *str, unsigned int line_cnt);

int is_digit(char *string);
int isnumber(char *str);

/* Linked list prototypes */
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

#endif /* MONTY_H */
