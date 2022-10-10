#include "monty.h"
/**
 * pint - a function that prints the value at top
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(global.line);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
	printf("%d\n", temp->n);
}
