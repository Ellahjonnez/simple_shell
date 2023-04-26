#include "shell.h"

/**
 * error_env - error message for environment in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_myshell *datash)
{
	int length;
	char *errmsg;
	char *ver_str;
	char *message;

	ver_str = a_itoa(datash->counter);
	message = ": Unable to add or remove from environment\n";
	length = _strlen(datash->argv[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(message) + 4;
	errmsg = malloc(sizeof(char) * (length + 1));
	if (errmsg == 0)
	{
		free(errmsg);
		free(ver_str);
		return (NULL);
	}

	_strcpy(errmsg, datash->argv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, ver_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, message);
	_strcat(errmsg, "\0");
	free(ver_str);

	return (errmsg);
}
/**
 * error_path - the error message for path and failure denied.
 * @datash: relevant data (counter, arguments).
 * Return: error string.
 */
char *error_path(data_myshell *datash)
{
	int length;
	char *ver_str;
	char *errmsg;

	ver_str = a_itoa(datash->counter);
	length = _strlen(datash->argv[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;
	errmsg = malloc(sizeof(char) * (length + 1));
	if (errmsg == 0)
	{
		free(errmsg);
		free(ver_str);
		return (NULL);
	}
	_strcpy(errmsg, datash->argv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, ver_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, ": Access denied\n");
	_strcat(errmsg, "\0");
	free(ver_str);
	return (errmsg);
}
