#include "monty.h"
/**
 * rotr - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void rotr(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *ist, *f_ist, *tail;

	if (s->size <= 1)
	{
		return;
	}
	else
	{
		ist = s->head;
	tail = s->tail;

	f_ist = ist->next;

		ist->prev = tail;

		tail->next = ist;
		f_ist->prev = NULL;
		ist->next = NULL;
		s->head = f_ist;
		s->tail = ist;
	}
}
