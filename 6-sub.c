#include "monty.h"
/**
 * sub - a function that substracts the top numbers
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *aux, *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(global.line);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	}
	temp = *stack;
	if (temp != NULL)
	{
		aux = temp->next;
		node = temp;
		if (aux != NULL)
			aux->prev = NULL;
		free(node);
		*stack = aux;
	}
}
