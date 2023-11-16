#include "monty.h"

/**
 * _pop - pops the very top
 * @stack: stack given by main
 * @line_cnt: line number for error messages
 *
 * Return: void
 * - The function  pop  takes a pointer to the stack and
 * the line count as arguments.
 * - It first checks if the stack is empty or if the stack
 * pointer is NULL. If either condition is true, it prints
 * an error message indicating that the stack is empty and
 * sets the  status  variable to  EXIT_FAILURE .
 * - If the stack is not empty, it creates a temporary pointer
 * tmp  and assigns the next node after the top of the stack to it.
 * - It frees the memory allocated for the top of the stack using
 * the  free  function.
 * - It updates the stack pointer to point to the next node ( tmp ).
 * - If the stack is not empty after the pop operation, it updates
 * the  prev  pointer of the new top node to  NULL .
 */
void _pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}
