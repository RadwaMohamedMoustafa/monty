#include "monty.h"

/**
 * is_alphabetic - check for the alphabitic order.
 * @c: the char.
 * Return: 0 or 1.
 */
int is_alphabetic(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/**
 * is_number - check for the number.
 * @c: the number.
 * Return: 0 or 1.
 */
int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_string_number - checks the string.
 * @string: the string.
 * Return: 0 or 1.
 */
int is_string_number(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-' || *string == '+')
		string++;
	while (*string)
	{
		if (is_number(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
