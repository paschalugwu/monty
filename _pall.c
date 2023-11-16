#include "monty.h"

/**
 * _pall - prints the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
*/
void _pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
