#include "shell.h"

/**
 * no_comment - removes comments from the input
 * @in: input string
 * Return: input without comments
 */

char *no_comment(char *in)
{
	int i, move;

	move = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				move = i;
		}
	}

	if (move != 0)
	{
		in = _realloc(in, i, move + 1);
		in[move] = '\0';
	}

	return (in);
}

/**
 * myshell_loop - the loop of the shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */

void myshell_loop(data_myshell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "MyShell$ :) ", 14);
		input = read_input_line(&i_eof);
		if (i_eof != -1)
		{
			input = no_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->state = 2;
				free(input);
				continue;
			}
			input = var_rep(input, datash);
			loop = spliter_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

