#include "shell.h"

/**
 * free_data - to free the data structure
 * @datash: the data structure
 * Return: no return value
 */

void free_data(data_myshell *datash)
{
	unsigned int j;

	for (j = 0; datash->my_environ[j]; j++)
	{
		free(datash->my_environ[j]);
	}

	free(datash->my_environ);
	free(datash->pid);
}

/**
 * data_init - Initializes the data structure
 * @datash: data structure
 * @argv: argument vector
 * Return: no return
 */

void data_init(data_myshell *datash, char **argv)
{
	unsigned int i;

	datash->argv = argv;
	datash->input = NULL;
	datash->args = NULL;
	datash->state = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->my_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->my_environ[i] = _strdup(environ[i]);
	}

	datash->my_environ[i] = NULL;
	datash->pid = a_itoa(getpid());
}

/**
 * main - Entry point
 * @argv: argument vector
 * @argc: argument count
 *
 * Return: 0 success always.
 */

int main(int argc, char **argv)
{
	data_myshell datash;
	(void) argc;

	signal(SIGINT, get_sigint);
	data_init(&datash, argv);
	myshell_loop(&datash);
	free_data(&datash);
	if (datash.state < 0)
		return (EXIT_FAILURE - 1);
	return (datash.state);
}

