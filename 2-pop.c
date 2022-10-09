#include "monty.h"

/**
 * pop - function to erases a node
 * @head: head of the stack
 * @line_number: lines number
 * Return: On success 1.
 * On error, -1 is returned.
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *aux, *node;

	(void)line_number;
	temp = *head;
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
