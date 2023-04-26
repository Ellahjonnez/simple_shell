#include "shell.h"

/**
 * copy_info - copies the info to create
 * a new env or alias
 * @name: the name of (env or alias)
 * @value: the value of (env or alias)
 * Return: new env or alias.
 */

char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */

void set_env(char *name, char *value, data_myshell *datash)
{
	int i;
	char *env_var, *env_name;

	for (i = 0; datash->my_environ[i]; i++)
	{
		env_var = _strdup(datash->my_environ[i]);
		env_name = _strtok(env_var, "=");
		if (_strcmp(env_name, name) == 0)
		{
			free(datash->my_environ[i]);
			datash->my_environ[i] = copy_info(env_name, value);
			free(env_var);
			return;
		}
		free(env_var);
	}

	datash->my_environ = _reallocdp(datash->my_environ,
			i, sizeof(char *) * (i + 2));
	datash->my_environ[i] = copy_info(name, value);
	datash->my_environ[i + 1] = NULL;
}

/**
 * _setenv - compares environment variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 * Return: 1 on success.
 */
int _setenv(data_myshell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes an environment variable
 * @datash: the relevant data (env name)
 * Return: 1 on success.
 */
int _unsetenv(data_myshell *datash)
{
	char **realloc_environ;
	char *env_var, *env_name;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->my_environ[i]; i++)
	{
		env_var = _strdup(datash->my_environ[i]);
		env_name = _strtok(env_var, "=");
		if (_strcmp(env_name, datash->args[1]) == 0)
		{
			k = i;
		}
		free(env_var);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->my_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->my_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->my_environ[k]);
	free(datash->my_environ);
	datash->my_environ = realloc_environ;
	return (1);
}
