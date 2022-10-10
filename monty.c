#include "monty.h"
global_stack global = {NULL, 0, NULL, NULL, NULL};

/**
 * main - Entry point of the program
 * @argc: arguments count
 * @argv: arguments vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	get_arg(argv);
	return (0);
}
