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
	stack_t *ssss;

	instruction_t monty_opcode[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", div_op}, {"mod", mod},
		{"mul", mul}, {"rotl", rotl},
		
		{NULL, NULL}};

	line = strtok(line, "\t\n");
	opcode = strtok(line, " ");
	if (!opcode || opcode[0] == '#')
		return (0);
	memory->args = strtok(NULL, " ");

	while (monty_opcode[i].opcode && opcode != NULL)
	{
		if (strcmp(opcode, monty_opcode[i].opcode) == 0)
		{
			monty_opcode[i].f(&ssss, memory->line_number);
			return (-1);
		};
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", memory->line_number, opcode);
	free_memory();
	exit(EXIT_FAILURE);
	return (1);


}