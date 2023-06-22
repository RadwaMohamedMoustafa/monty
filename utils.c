#include "monty.h"

void check_memory(void * p)
{
	if (p == NULL)
	{
		print_error("Error: malloc failed\n");
		free_memory();
		exit(EXIT_FAILURE);
	}
}
