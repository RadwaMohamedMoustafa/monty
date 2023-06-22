#include "monty.h"

/**
 * print_error - print the error.
 * @message: the message.
 * Return: void.
 */
void print_error(char *message)
{
	int length = strlen(message);

	write(STDERR_FILENO, message, length);
}

/**
 * print - prints the string.
 * @message: the message.
 * Return: void.
 */
void print(char *message)
{
	int length = strlen(message);

	write(STDOUT_FILENO, message, length);
}
