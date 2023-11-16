#include "monty.h"

/**
 * _mod - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 * - The function  mod  takes a pointer to the stack and the line count
 * as arguments.
 * - It first checks if the stack is empty or if the stack has less than
 * two elements (top and next). If either condition is true, it prints an
 * error message indicating that the stack is too short and sets the
 * status  variable to  EXIT_FAILURE.
 * - It then checks if the value of the top element ( ((*stack)->n) ) is 0.
 * If it is, it prints an error message indicating division by zero and
 * sets the  status  variable to  EXIT_FAILURE.
 * - If the stack has at least two elements and the top element is not 0,
 * it calculates the remainder of the division of the second top element
 * and the top element by using the  %  operator.
 * - It calls the  pop  function to remove the top element from the stack.
 * - Finally, it updates the value of the new top element ( (*stack)->n )
 * with the calculated result.
 */
void _mod(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	_pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
