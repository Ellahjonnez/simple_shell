#include "shell.h"

/**
 * read_input_line - reads the input string.
 * @n_eof: return value of getline function
 * Return: input string
 */

char *read_input_line(int *n_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*n_eof = getline(&input, &bufsize, stdin);

	return (input);
}

