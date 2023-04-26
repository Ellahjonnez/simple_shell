#include "shell.h"

/**
 * env_cmp - compares the env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */

int env_cmp(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - to get the environment variable
 * @name: name of the environment variable
 * @_environ: the environment variable
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */

char *_getenv(const char *name, char **_environ)
{
	char *env_ptr;
	int i, mov;

	/* Initializes environment pointer value */
	env_ptr = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* Declaring env in the header file */
	for (i = 0; _environ[i]; i++)
	{
		mov = env_cmp(_environ[i], name);
		if (mov)
		{
			env_ptr = _environ[i];
			break;
		}
	}

	return (env_ptr + mov);
}

/**
 * _env - prints the evironment variables
 * @datash: data relevant.
 * Return: 1 on success.
 */

int _env(data_myshell *datash)
{
	int i, j;

	for (i = 0; datash->my_environ[i]; i++)
	{

		for (j = 0; datash->my_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->my_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->state = 0;

	return (1);
}
