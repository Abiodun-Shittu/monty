#include "monty.h"

/**
 * get_arg - function that get the arguments and proccess the file
 * @argv: arguments vector
 * Return: 0 success otherwise 1
 */
int get_arg(char *argv[])
{
	FILE *fp;
	char *line = NULL, *buffer[512];
	size_t size = 0;
	stack_t *head = NULL;
	unsigned int count;

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		count++;
		get_buffer(line, buffer);
		if (buffer != NULL)
		{
			check_digit(buffer[1]);
			exe(buffer[0], &head, count);
		}
		else
		{
			count++;
		}
	}
	fclose(fp);
	free(line);
	free_stack_t(head);
	exit(EXIT_SUCCESS);
}

/**
 * exe - function that select the operation and execute them
 * @op: operation
 * @stack: stack root
 * @line_number: line number in file
 * Return: 0 success, failure 1
 */
int exe(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	if (op == NULL)
		return (0);

	for (i = 0; op_codes[i].opcode != NULL; i++)
	{
		if (strcmp(op_codes[i].opcode, op) == 0)
		{
			if (strcmp(op_codes[i].opcode, op_codes[0].opcode) == 0)
				check_digit(op);
			op_codes[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}

/**
 * get_buffer - function that takes the arguments and save the info in buffer
 * @string: string obtained
 * @my_tokens: tokens from strtok
 */
void get_buffer(char *string, char **my_tokens)
{
	int i = 0;
	char *token;
	char *separators = " \r\a\t\n";

	if (my_tokens == NULL)
		exit(EXIT_FAILURE);
	token = strtok(string, separators);
	while (token != NULL)
	{
		my_tokens[i] = token;
		i++;
		token = strtok(NULL, separators);
	}
	my_tokens[i] = NULL;
}

/**
 * free_stack_t -function that freezes memory
 * @head: stack root
 */
void free_stack_t(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
