#include "monty.h"
/**
 * pop - erases a node
 * @head: head of the stack
 * @line_number: line of the comand
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *aux, *node;

	(void)line_number;
	temp = *head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(global.line);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	if (temp != NULL)
	{
		aux = temp->next;
		node = temp;
		if (aux != NULL)
			aux->prev = NULL;
		free(node);
		*head = aux;
	}
}
