#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *tempStack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	tempStack = (*stack)->next;

	while (temp->next)
		temp = temp->next;

	tempStack->prev = NULL;
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	*stack = tempStack;
}
