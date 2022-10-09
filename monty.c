#include "monty.h"
int global_num = 0;

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Zero (0) on success
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
