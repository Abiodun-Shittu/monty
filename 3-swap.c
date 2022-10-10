#include "monty.h"
/**
 * swap - change info from two nodes
 * @stack: head of the stack
 * @line_number: line of the comand
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp, aux;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(global.line);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL && (*stack)->next != NULL)
	{	temp = (*stack)->n;
		aux = (*stack)->next->n;
		(*stack)->n = aux;
		(*stack)->next->n = temp;
	}
}
