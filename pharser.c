#include "monty.h"

int pharse_line(char *line)
{
	char *opcode;
	char *intger;
	int i = 0;
	stack_t *t;

	instruction_t monty_opcode[] = {
		{"push", push},
		{"pall", push},
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


}
