#include "monty.h"
/**
 * push - puts a number into the top node
 * @head: a pointer to the stack
 * @line_number: the number of lines
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	global.newnode = new_node;
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		free(global.line);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	new_node->n = global.global_number;
	if (*head != NULL)
		(*head)->prev = new_node;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
}
/**
 * pall - prints all elements of the stack
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *temp = *stack;

	(void)line_number;
	for (; temp != NULL; temp = temp->next)
	{
		printf("%d\n", temp->n);
		i++;
	}
}

/**
 * check_digit_push - checks if data is an integer
 * @tokens: a token
 * @line_number: the number of lines
 * Return: 0 if true, 1 if was converted
 */

int check_digit_push(char *tokens, unsigned int line_number)
{
	int i = 0;

	if (tokens == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(global.line);
		fclose(global.fp);
		free_stack_t(global.newnode);
		exit(EXIT_FAILURE);
	}
	if (tokens[i] == '-')
		i++;
	for (; tokens[i] != '\0'; i++)
	{
		if (tokens[i] < '0' || tokens[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(global.line);
			fclose(global.fp);
			free_stack_t(global.newnode);
			exit(EXIT_FAILURE);
		}
	}

	global.global_number = atoi(tokens);
	return (1);
}
/**
 * check_digit - checks if data is an integer
 * @tokens: a token
 * @line_number: the number of lines
 * Return: 0 if true, 1 if was converted
 */

int check_digit(char *tokens, unsigned int line_number)
{
	(void)line_number;
	(void)tokens;
	return (0);
}
