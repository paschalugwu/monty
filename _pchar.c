#include "monty.h"

/**
 * _pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 * - The function _pchar takes a pointer to the stack and the line
 * count as argument.
 * - It first checks if the stack is empty or if the stack pointer is NULL.
 * If either condition is true, it prints an error message indicating that
 * the stack is empty and sets the status variable to EXIT_FAILURE.
 * - It then checks if the integer value at the top of the stack ((*stack)->)
 * is within the range of ASCII values. If the value is not in the ASCII table,
 * it prints an error message indicating that the value is out of range and
 * sets the status variable to EXIT_FAILURE
 * - If the value is within the ASCII range, it uses the printf function to
 * to print the character corresponding to the ASCII value ((*stack)->n),
 * followed by a new line.
*/
void _pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
