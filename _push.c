#include "monty.h"

void _push(stack_t **stack, unsigned int line_cnt);
/**
 * _push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
*/
void _push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.argument;
	/**
	 * The '_push' function takes a pointer to the stack and the line
	 * number as arguments. It initializes a variable `n` to store the
	 * argument passed to the push opcode
	*/

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		status = EXIT_FAILURE;
		return;
		/**
		 * The is_digit function is a helper function that checks if the
		 * string is a valid imteger. If the argument is not a valid integer,
		 * it prints an error message with the line number and sets the
		 * status to EXIT_FAILURE
		*/
	}
	if (global.data_struct == 1)
	{
		if (!_add_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!_queue_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	/**
	 * Depending on the data structure type (stack or queue),
	 * the function calls either the _add_node or _queue_node
	 * function to add the element to the stack. If the function
	 * fails to add the node, it returns and sets the status to
	 * EXIT_FAILURE
	*/
}
