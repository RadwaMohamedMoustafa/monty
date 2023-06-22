#include "monty.h"

int is_alphabetic(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_string_number(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (is_number(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
