#include "monty.h"

void print_error(char *message)
{
	int length = strlen(message);
	write(STDERR_FILENO, message, length);
}

void print(char *message)
{
	int length = strlen(message);
	write(STDOUT_FILENO, message, length);
}
