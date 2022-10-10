#include "monty.h"
/**
 * pstr - print as characters the stack values
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	while (temp != NULL && (temp->n > 0 && temp->n < 128))
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
