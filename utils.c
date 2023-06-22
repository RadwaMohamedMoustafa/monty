#include "monty.h"

/**
 * check_memory - checks for the memory.
 * @p: the string.
 * Return: void.
 */
void check_memory(void *p)
{
	if (p == NULL)
	{
		print_error("Error: malloc failed\n");
		free_memory();
		exit(EXIT_FAILURE);
	}
}
