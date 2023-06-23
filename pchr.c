#include "monty.h"

/**
 * pchar - implementing the pall op-code.
 * @st: the stack.
 * @line_number: the line number.
 * Return: void.
 */
void pchar(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number)
{
	stack *s = memory->stack;
	stack_t *node = s->tail;

    

	if (s->size > 0 && node->n >= 0 && node->n <= 127)
	{
		printf("%c\n", node->n);
	}
	else
	{
        if(s->size > 0 )
        {
            fprintf(stderr, "L%u: can't pchar, value out of range\n", memory->line_number);
        }
        else
        {
	        fprintf(stderr, "L%u: can't pchar, stack empty\n", memory->line_number);
        }
		free_memory();
		exit(EXIT_FAILURE);
	}
}