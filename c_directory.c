#include "shell.h"

/**
 * c_directory - changes the directory
 * @datash: data relevant
 * Return: 1 on success
 */
int c_directory(data_myshell *datash)
{
	char *cd_dir;
	int ishome, is_home, is_ddash;

	cd_dir = datash->args[1];

	if (cd_dir != NULL)
	{
		ishome = _strcmp("$HOME", cd_dir);
		is_home = _strcmp("~", cd_dir);
		is_ddash = _strcmp("--", cd_dir);
	}

	if (cd_dir == NULL || !ishome || !is_home || !is_ddash)
	{
		cd_home(datash);
		return (1);
	}

	if (_strcmp("-", cd_dir) == 0)
	{
		cd_prev(datash);
		return (1);
	}

	if (_strcmp(".", cd_dir) == 0 || _strcmp("..", cd_dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
