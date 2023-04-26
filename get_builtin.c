#include "shell.h"

/**
 * get_builtin - builtin functions for the command in the arg
 * @cmd: the command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(data_myshell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_myshell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", c_directory },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].fp);
}

