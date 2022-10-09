#include "monty.h"

/**
 * swap - function that change info from two nodes
 * @stack: head of the stack
 * @line_number: lines number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp, aux;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->n;
		aux = (*stack)->next->n;
		(*stack)->n = aux;
		(*stack)->next->n = temp;
	}
}
