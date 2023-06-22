#include "monty.h"

void push(stack **stack, unsigned int line_number)
{
	
	int args;
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
	stack_push(*stack,args);
}

void pall(stack **st, __attribute__((unused)) unsigned int line_number)
{
	stack *s = *st;
	stack_t *node = s->head;

	if (s->size <=0)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
