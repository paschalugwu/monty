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
	/**
	 * the _pall function takes a pointer to the stack and the line
	 * number as arguments. It calls the print_stack function to print
	 * all the values on the stack
	*/
}
