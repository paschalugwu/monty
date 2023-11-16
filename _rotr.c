#include "monty.h"

/**
 * _rotr - rotates the last node of a stack_t stack
 * @stack: stack head
 * @line_count: line count
 *
 * Return: void
 * - The function _rotr takes a double pointer to the stack and the
 * line count as arguments
 * - It first checks if the stack is empty or contains only one
 * element. If either condition is true, it returns.
 * - If the stack has more than one element, it creates two stack
 * pointers, bottom and prev, and initializes bottom to the stack pointer
 * - It then transverses the stack to find the last node, which will
 * become the new top element.
 * - It updates next and prev pointers of the last node (buttom)
 * and the previous node (prev) accordingly.
 * - It breaks the link between the previous top elements and the new
 * top element by setting the next_pointer of the previous top element
 * to NULL
 * - Finally, it updates the stack pointer to point to the new top element
*/
void _rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
