#include "monty.h"

/**
 * _pint - print the top data
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 * - The function  _pint  takes a pointer to the stack and the
 * line count as arguments.
 * - It first checks if the stack is empty or if the stack pointer
 * is NULL. If either condition is true, it prints an error message
 * indicating that the stack is empty and sets the  status  variable
 * to  EXIT_FAILURE .
 * - If the stack is not empty, it prints the value at the top of the
 * stack using the  printf  function, followed by a new line.
 */
void _pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
