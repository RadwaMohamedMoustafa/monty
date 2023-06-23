#include "monty.h"


/**
 * pstr - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */

void pstr(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *node = s->tail;
		
	while (node != NULL)
	{
        if(node->n <= 0 || node->n > 127)
            break;
		printf("%c", node->n);
		node = node->prev;
	}
    printf("\n");
}
