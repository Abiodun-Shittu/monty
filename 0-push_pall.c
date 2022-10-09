#include "monty.h"

/**
 * push - function that puts a number into the top node
 * @head: a pointer to the stack
 * @line_number: lines number
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = global_number;
	if (*head != NULL)
		(*head)->prev = new_node;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
}

/**
 * pall - function that prints all elements of the stack
 * @stack: a pointer to the stack
 * @line_number: lines number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *temp = *stack;

	(void)line_number;
	for (i = 0; temp != NULL; i++)
	{
		temp = temp->next;
		printf("%d\n", temp->n);
	}
}

/**
 * check_digit - Function that checks if the data is an integer
 * @tokens: a token
 * Return: 0 if true, 1 if was converted
 */

int check_digit(char *tokens)
{
	int i = 0;

	if (tokens == NULL)
		return (0);
	if (tokens[i] == '-')
		i++;
	for (; tokens[i]; i++)
	{
		if (tokens[i] < 48 || tokens[i] > 57)
			return (0);
	}

	global_number = atoi(tokens);
	return (1);
}
