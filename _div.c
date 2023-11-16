#include "monty.h"

/**
 * _div - divides the next top value by the top value
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 * -The function _div takes a pointer to the stack and the line count as
 * arguments.
 * - It first checks if the stack is empty or if the stack has two elements
 * (top and next). If either conditions is true, it prints an error message
 * indicating that the stack is too short and sets the status variable to
 * EXIT_FAILURE.
 * - It then checks if the top element of the stack is 0. If it is, it prints
 * an error message indicating division by zero and sets the status variable
 * to EXIT_FAILURE.
 * - If the stack has at least two elements and the top element is not zero,
 * it calculates the division of the second top element by the top element
 * by dividing ((*stack)->next->n) by ((*stack)->n)
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	_pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
