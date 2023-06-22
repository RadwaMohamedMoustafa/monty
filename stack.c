#include "monty.h"


void init_stack(stack **s) {
	*s = (stack *) malloc(sizeof(stack));
	check_memory(*s);
	(*s)->size = 0;
	(*s)->head = 0;
	(*s)->tail = 0;
}

stack_t *stack_push(stack *s, int data) {
	/* Check Stack Is Empty */

	stack_t *temp;
	stack_t *node = (stack_t*) malloc(sizeof(stack_t));
	check_memory(node);

	node->n=data;
	node->prev=NULL;
	node->next=NULL;

	if (s->size == 0)
	{
		s->head = node;
		s->tail = node;

	}else
	{
		temp = (s->tail);
		temp->next = node;
		node->prev = temp;
		(s->tail) = node;

	}
	s->size++;
	return node;
}

stack_t *stack_pop(stack *s)
{
	stack_t *node, *temp;
	node = s->tail;
	temp = node->prev;
	s->tail = temp;

	if (s->size > 1)
		temp->next = NULL;


	s->size--;

	return node;
}



void free_stack(stack *s)
{
	stack_t *data;
	while (s->size > 0)
	{
		data = stack_pop(s);
		free(data);
	}

	free(s);
}
