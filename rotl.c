#include "monty.h"
/**
 * rotl - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void rotl(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *ist, *f_tail, *tail;

	if (s->size <= 1)
	{
		return;
	}
	else
	{
		ist = s->head;
		tail = s->tail;
		f_tail = tail->prev;


		ist->prev = tail;

		tail->next = ist;
		tail->prev = NULL;

		f_tail->next = NULL;

		s->head = tail;
		s->tail = f_tail;
	}
}
