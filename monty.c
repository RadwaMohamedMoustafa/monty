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
	stack_t *s;
	size_t len = 0;

	initMemory();
	init_stack(&ss);
	if (argc != 2)
	{
		print_error("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		print_error("Error: Can't open file ");
		print_error(argv[1]);
		print_error("\n");
		exit(EXIT_FAILURE);
	}
	memory->file_ptr = file;
	memory->stack = ss;
	while ((read = getline(&memory->line, &len, file)) != -1)
	{
		if (read > 1)
		{
			pharse_line(memory->line);
			memory->line_number++;
		}
	}
	free_memory();

	printf("No Memery Leack\n");
	return (0);
}
