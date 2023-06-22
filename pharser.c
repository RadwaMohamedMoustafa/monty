#include "monty.h"

/**
 * pharse_line - check the op_code.
 * @line: the op_code.
 * Return: 1 or -1.
 */
int pharse_line(char *line)
{
	char *opcode;
	int i = 0;

	instruction_t monty_opcode[] = {
		{"push", push},
		{"pall", pall},
		{"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{NULL, NULL}};

	line = strtok(line, "\t\n");
	opcode = strtok(line, " ");
	if (!opcode)
		return (0);
	memory->args = strtok(NULL, " ");

	while (monty_opcode[i].opcode && opcode != NULL)
	{
		if (strcmp(opcode, monty_opcode[i].opcode) == 0)
		{
			monty_opcode[i].f(&memory->stack, memory->line_number);
			return (-1);
		};
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n",
			memory->line_number, opcode);
	free_memory();
	exit(EXIT_FAILURE);
	return (1);


}
