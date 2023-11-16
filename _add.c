#include "monty.h"

/**
 * _add - adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 * - The function _add takes a pointer to the stack and the line count as
 * arguments.
 * - It first checks if the stack is empty or if the stack has less than
 * two elements (top and next). If either condition is true, it prints an
 * error message indicating that the stack is too shortand sets status
 * variable to EXIT_FAILURE.
 * - If the stack has at least two elements, it calculates the sum of the
 * values of the top two elements by adding ((*stack)->next->n) and
 * ((*stack)->n).
 * - It then calls the pop function to remove the top element from stack.
 * - Finally, it updates the value of the new top element ((*stack)->n)
 * with the calculated result.
*/
void _add(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	_pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
