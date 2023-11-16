#include "monty.h"

/**
 * _sub - substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 * - The function _sub takes a pointer to the stack and the line count as
 * arguments.
 * - It first checks if the stack is empty or if the stack has less than two
 * elements (top and next). If either condition is true, it prints an error
 * message indicating that the stack is too short and sets the status
 * variable to EXIT_FAILURE
 * - If the stack has at least 2 elements, it calculates the difference
 * between the values of the top and second top elements by subtracting
 * ((*stack)->n) with the caalculated result.
*/
void _sub(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	_pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
