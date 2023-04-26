#include "shell.h"

/**
 * check_env - checks if the variable is an env variable
 * @h: the head of linked list
 * @in: the input string
 * @data: the data structure
 * Return: no return
 */

void check_env(var_list **h, char *in, data_myshell *data)
{
	int row, charc, j, lval;
	char **_envr;

	_envr = data->my_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, charc = 0; _envr[row][charc]; charc++)
		{
			if (_envr[row][charc] == '=')
			{
				lval = _strlen(_envr[row] + charc + 1);
				add_rvar_node(h, j, _envr[row] + charc + 1, lval);
				return;
			}

			if (in[j] == _envr[row][charc])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */

int check_vars(var_list **h, char *in, char *st, data_myshell *data)
{
	int i, first, lpd;

	first = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, first), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - replaces any string with variables
 * @head: the head of the linked list
 * @input: the input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */

char *replaced_input(var_list **head, char *input, char *new_input, int nlen)
{
	var_list *index;
	int i, j, k;

	index = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(index->len_variable) && !(index->len_value))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (index->len_variable && !(index->len_value))
			{
				for (k = 0; k < index->len_variable; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < index->len_value; k++)
				{
					new_input[i] = index->value[k];
					i++;
				}
				j += (index->len_variable);
				i--;
			}
			index = index->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * var_rep - calls functions to replace string into vars
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */

char *var_rep(char *input, data_myshell *datash)
{
	var_list *head, *index;
	char *status, *new_input;
	int olen, nlen;

	status = a_itoa(datash->state);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	index = head;
	nlen = 0;

	while (index != NULL)
	{
		nlen += (index->len_value - index->len_variable);
		index = index->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_var_list(&head);

	return (new_input);
}

