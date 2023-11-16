#include "monty.h"

/**
 * _nop - this function actually does nothing. It s simply a placeholder
 * instruction that is used for various purposes, such as alignment or as
 * a placeholder for future instructions
 * @stack: doesn't do anything
 * @line_cnt: it doesn't do anything
 *
 * Return: void
 * - The function _nop takes a pointer to the stack and the line count as
 * arguments.
 * - It uses (void) to explicitly indicate that the _nop opcode doesn't
 * require any specific action.
 * - Since the nope opcode doesn't do anything, the function body is empty.
*/
void _nop(stack_t **stack, unsigned int line_cnt)
{
	(void) stack;
	(void) line_cnt;
}
