#include "shell.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @errval: the error value
 * Return: error
 */
int get_error(data_myshell *datash, int errval)
{
	char *get_err;

	switch (errval)
	{
	case -1:
		get_err = error_env(datash);
		break;
	case 126:
		get_err = error_path(datash);
		break;
	case 127:
		get_err = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			get_err = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			get_err = get_error_cd(datash);
		break;
	}

	if (get_err)
	{
		write(STDERR_FILENO, get_err, _strlen(get_err));
		free(get_err);
	}

	datash->state = errval;
	return (errval);
}

