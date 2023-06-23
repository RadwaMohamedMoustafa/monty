#include "monty.h"

/**
 * push - implementing the push op_code.
 * @ppp: the stack.
 * @line_number: the number of lines.
 * Return: void.
 */
void push(__attribute__((unused)) stack_t **ppp,
		__attribute__((unused)) unsigned int line_number)
{
	int args;
	stack *stack = memory->stack;

	if (memory->args != NULL)
	{
		if (is_string_number(memory->args))
			args = atoi(memory->args);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", memory->line_number);
			free_memory();
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		fprintf(stderr, "L%u: usage: push integer\n", memory->line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}
	stack_push(stack, args);
}
/**
 * pall - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */

void pall(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *node = s->tail;

	if (s->size <= 0)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}


/**
 * pint - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void pint(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *node = s->tail;

	if (s->size > 0)
	{
		printf("%d\n", node->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", memory->line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}
}


/**
 * pop - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void pop(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *t;

	if (s->size > 0)
	{
		t = stack_pop(s);
		free(t);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", memory->line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}
}
