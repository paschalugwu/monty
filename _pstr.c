#include "monty.h"

/**
 * _pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: nothing
 * - We declare a variable current of type stack_t, and initialize
 * it with the value of *stack. This variable will be used to
 * transverse the stack
 * - We the use while loop that iterates as lomg
 * as current is not null
 * - Inside the while loop, add an if condition to check if the
 * value of  current->n  is less than or equal to 0, or greater
 * than 127. If either condition is true, break out of the loop.
 * - Inside the if condition, we use the  putchar  function to print
 * the character corresponding to the ASCII value  current->n .
 * - After printing the character, update the  current  variable to
 * point to the next element in the stack.
 * - After the while loop, use the  putchar  function to print a
 * new line
 */
void _pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
