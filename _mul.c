#include "monty.h"

/**
 * _mul - divides the next top value by the top value
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 * - The function  _mul  takes a pointer to the stack and the line
 * count as arguments.
 * - It first checks if the stack is empty or if the stack has less
 * than two elements (top and next). If either condition is true, it
 * prints an error message indicating that the stack is too short and
 * sets the  status  variable to  EXIT_FAILURE.
 * - If the stack has at least two elements, it calculates the product
 * of the values of the second top element and the top element by
 * multiplying  ((*stack)->next->n)  and  ((*stack)->n).
 * - It then calls the  pop  function to remove the top element from the
 * stack.
 * - Finally, it updates the value of the new top element ( (*stack)->n )
 * with the calculated result.
 */
void _mul(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	_pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
