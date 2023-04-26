#include "shell.h"

/**
 * char_repetitions - counts the repetitions of a char
 * @input: the input string
 * @i: index
 * Return: repetitions
 */

int char_repetitions(char *input, int i)
{
	if (*(input - 1) == *input)
		return (char_repetitions(input - 1, i + 1));

	return (i);
}

/**
 * error_sep - finds syntax errors
 * @input: the input string
 * @i: the index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep(char *input, int i, char last)
{
	int counter;

	counter = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			counter = char_repetitions(input, 0);
			if (counter == 0 || counter > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			counter = char_repetitions(input, 0);
			if (counter == 0 || counter > 1)
				return (i);
		}
	}

	return (error_sep(input + 1, i + 1, *input));
}

/**
 * first_char - finds index of the first char
 * @input: the input string
 * @i: index
 * Return: 1 if there is an error. eles return 0.
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 * @datash: the data structure
 * @input: the input string
 * @i: index of the error
 * @bool: to control the error msg
 * Return: no return
 */
void print_syntax_error(data_myshell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *errmsg, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error :( \"";
	msg3 = "\" unexpected\n";
	counter = a_itoa(datash->counter);
	length = _strlen(datash->argv[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	errmsg = malloc(sizeof(char) * (length + 1));
	if (errmsg == 0)
	{
		free(counter);
		return;
	}
	_strcpy(errmsg, datash->argv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, counter);
	_strcat(errmsg, msg2);
	_strcat(errmsg, msg);
	_strcat(errmsg, msg3);
	_strcat(errmsg, "\0");

	write(STDERR_FILENO, errmsg, length);
	free(errmsg);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print syntax error
 * @datash: the data structure
 * @input: the input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_myshell *datash, char *input)
{
	int start = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(input, &start);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, start, 0);
		return (1);
	}

	i = error_sep(input + start, 0, *(input + start));
	if (i != 0)
	{
		print_syntax_error(datash, input, start + i, 1);
		return (1);
	}

	return (0);
}

