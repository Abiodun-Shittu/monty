#include "monty.h"
/**
 * pchar - prints the char representation of the top-stack
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(global.line);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(global.line);
		fclose(global.fp);
		free_stack_t(global.newnode);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
