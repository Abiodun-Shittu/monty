#include "monty.h"
/**
 * rotr - puts the bottom node to the top of stack
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *head;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	head = *stack;
	last = (*stack)->next;

	while (last->next)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	*stack = last;
}
