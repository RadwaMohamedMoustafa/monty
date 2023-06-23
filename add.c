#include "monty.h"

/**
 * add - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void add(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *t;
	int temp;

	if (s->size > 1)
	{
		temp = s->tail->n;
		t = stack_pop(s);
		free(t);
		s->tail->n += temp;

	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", memory->line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}
}
