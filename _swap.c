#include "monty.h"

/**
 * _swap - swaps data from top to pevious
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 * - The function _swap takes a pointer to the stack and the line count as
 * arguments.
 * - It first checks if the stack is empty or if the stack has less than
 * two elements (top and next). If either condition is true, it prints an
 * error message indicating that the stack is too shot and sets the status
 * variable to EXIT_FAILURE.
 * - If the stack has at least two elements, it creates a temporary pointer
 * tmp and assigns the stack pointer to it.
 * - It creates a temporary variable tmp_n and assigns the value of the
 * top eement (tmp->n) to it.
 * - It swaps the values of the top element and the next element by assigning
 * tmp->next->n to tmp->n and tmp_n to tmp->next->n
*/
void _swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;

}
