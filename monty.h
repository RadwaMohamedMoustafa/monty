#ifndef STACK_QUE_DS_H
#define STACK_QUE_DS_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>


#define MAX_LINE_LENGTH 1024
#define SizeOfMalloc 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct stack - stack nodes.
 * @head: the head of the nodes.
 * @tail: the tail of the nodes.
 * @size: the size.
 *
 * Description: this struct carries the stack nodes.
 */
typedef struct stack
{
	struct stack_s *head;
	struct stack_s *tail;
	unsigned int size;

} stack;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Memory - memory handler.
 * @file_ptr: the file.
 * @stack: stack.
 * @line_number: the line number.
 * @line: the line.
 * @args: the arguments.
 *
 * Description: carry the memory handlers.
 */
typedef struct Memory
{
	FILE  *file_ptr;
	stack *stack;
	unsigned int line_number;
	char *line;
	char *args;

} Memory;

void initMemory(void);
void free_memory(void);
extern Memory *memory;

void init_stack(stack **s);
stack_t *stack_push(stack *s, int data);
stack_t *stack_pop(stack *s);
void free_stack(stack *s);

/* printing */
void print_error(char *message);
void print(char *message);


/* Pharser */
int pharse_line(char *line);

/* instruction */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
/* Strings   */
int is_alphabetic(char c);
int is_number(char c);
int _atoi(char *s);
int is_string_number(char *string);


/* utils */
void check_memory(void *p);

/* Swap */
void swap(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number);

void add(__attribute__((unused)) stack_t **st,
		__attribute__((unused)) unsigned int line_number);

/*Testing */
void *mock_malloc(size_t size);
#endif
