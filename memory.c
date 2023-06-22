#include "monty.h"

void initMemory(void)
{
	memory = (Memory *)malloc(sizeof(Memory));
	check_memory(memory);
	memory->file_ptr = NULL;
	memory->stack = NULL;
	memory->line_number = 1;
	memory->args = NULL;
	memory->line = NULL;

}


void free_memory(void)
{
	fclose(memory->file_ptr);
	free_stack(memory->stack);
	free(memory->line);
	free(memory);

}
