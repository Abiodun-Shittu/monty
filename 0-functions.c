#include "monty.h"

/**
 * get_arg - get the arguments and proccess the file
 * @argv: arguments vecto
 * Return: 0 success otherwise 1
 */

int get_arg(char *argv[])
{
	FILE *fp = NULL;
	char *line = NULL, *buffer[4096];
	size_t size = 0;
	stack_t *head = NULL;
	unsigned int count = 0;

	fp = fopen(argv[1], "r");
	global.fp = fp;
	global.head = head;
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
/*		fclose(fp);*/
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		global.line = line;
		count++;
		get_buffer(line, buffer); /* to tokenize the line*/
		if (buffer != NULL)
		{
			if (buffer[0] != '\0' && strcmp("push", buffer[0]) == 0)
				check_digit_push(buffer[1], count);
			else
				check_digit(buffer[1], count);
			exe(buffer[0], &head, count);
		}
		else
		{
			count++;
		}
	}
	free_stack_t(head);
	free(global.line);
	fclose(fp);
	exit(EXIT_SUCCESS);
}
/**
 * exe - select the operation and execute them
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
	{"sub", sub},
	{"div", f_div},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{NULL, NULL}
};
	if (op == NULL)
	{
		free(op);
		return (0);
	}
	for (i = 0; op_codes[i].opcode != NULL; i++)
	{
		if (strcmp(op_codes[i].opcode, op) == 0)
		{
			op_codes[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	free(global.line);
	fclose(global.fp);
/*	free_stack_t(global.newnode);*/
	exit(EXIT_FAILURE);
}
/**
 * get_buffer - takes the arguments and save the info in buffer
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
	while (token != NULL && token[0] != '#')
	{
		my_tokens[i] = token;
		i++;
		token = strtok(NULL, separators);
	}
	my_tokens[i] = NULL;
}
/**
 * free_stack_t - freezes memory
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
