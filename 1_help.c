#include "shell.h"

/**
 * help - Help information for the builtin help.
 * Return: no return
 */

void help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of the builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * help_alias - Help information for the builtin alias.
 * Return: no return
 */

void help_alias(void)
{
	char *help_a = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help_a, _strlen(help_a));
	help_a = "\tDefine/display all aliases.\n ";
	write(STDOUT_FILENO, help_a, _strlen(help_a));
}
/**
 * help_cd - Help information for the builtin alias.
 * Return: no return
 */

void help_cd(void)
{
	char *help_c = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help_c, _strlen(help_c));
	help_c = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help_c, _strlen(help_c));
}
