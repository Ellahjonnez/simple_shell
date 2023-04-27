#include "shell.h"

/**
 * cmd_line - finds builtins and commands
 * @datash: relevant data (args)
 * Return: 1 on success.
 */
int cmd_line(data_myshell *datash)
{
	int (*builtin)(data_myshell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
