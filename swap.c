#include "monty.h"

/**
 * swap - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void swap(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	int temp;

	if (s->size > 1)
	{
		temp = s->tail->n;
		s->tail->n = s->tail->prev->n;
		s->tail->prev->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", memory->line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}
}
