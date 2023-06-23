#include "monty.h"

Memory *memory;

/**
 * main - main function.
 * @argc: count of arguments.
 * @argv: the arguments.
 * Return: zero.
 */

int main(int argc, char **argv)
{
	ssize_t read;
	stack *ss;
	FILE *file;
	size_t len = 0;

	initMemory();
	init_stack(&ss);
	if (argc != 2)
	{
		free(memory);
		free(ss);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		free(memory);
		free(ss);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	memory->file_ptr = file;
	memory->stack = ss;
	while ((read = getline(&(memory->line), &len, file)) != -1)
	{
		if (read > 1)
		{
			pharse_line(memory->line);
			memory->line_number++;
		}
	}
	free_memory();
	return (0);
}
