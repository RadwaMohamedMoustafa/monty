#include "monty.h"

/**
 * mock_malloc - tests the malloc failure.
 * @size: the size.
 * Return: void.
 */
void *mock_malloc(__attribute__((unused)) size_t size)
{
	return (NULL);
}
