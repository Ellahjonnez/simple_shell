#include "shell.h"

/**
 * strcat_cd - to concatenate messages for the cd error
 * @datash: data relevant (directory)
 * @message: the message to print
 * @errmsg: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_myshell *datash, char *message,
		char *errmsg, char *ver_str)
{
	char *illegal_flag;

	_strcpy(errmsg, datash->argv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, ver_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, message);

	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(errmsg, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(errmsg, datash->args[1]);
	}

	_strcat(errmsg, "\n");
	_strcat(errmsg, "\0");
	return (errmsg);
}

/**
 * get_error_cd - the error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *get_error_cd(data_myshell *datash)
{
	int length, len_id;
	char *errmsg, *ver_str, *message;

	ver_str = a_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		message = ": Unsopported format ";
		len_id = 2;
	}
	else
	{
		message = ": Unable to use cd ";
		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->argv[0]) + _strlen(datash->args[0]);
	length += _strlen(ver_str) + _strlen(message) + len_id + 5;
	errmsg = malloc(sizeof(char) * (length + 1));

	if (errmsg == 0)
	{
		free(ver_str);
		return (NULL);
	}

	errmsg = strcat_cd(datash, message, errmsg, ver_str);

	free(ver_str);

	return (errmsg);
}

/**
 * error_not_found - this is error message for command not found
 * @datash: relevant data are (counter, arguments)
 * Return: Error message
 */

char *error_not_found(data_myshell *datash)
{
	int length;
	char *errmsg;
	char *ver_str;

	ver_str = a_itoa(datash->counter);
	length = _strlen(datash->argv[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 16;
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
	_strcat(errmsg, ": not found\n");
	_strcat(errmsg, "\0");
	free(ver_str);
	return (errmsg);
}

/**
 * error_exit_shell - error message for exiting in get_exit
 * @datash: relevant data are (counter, arguments)
 * Return: Error message
 */

char *error_exit_shell(data_myshell *datash)
{
	int len;
	char *errmsg;
	char *ver_str;

	ver_str = a_itoa(datash->counter);
	len = _strlen(datash->argv[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	errmsg = malloc(sizeof(char) * (len + 1));
	if (errmsg == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(errmsg, datash->argv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, ver_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, ": Illegal number: ");
	_strcat(errmsg, datash->args[1]);
	_strcat(errmsg, "\n\0");
	free(ver_str);

	return (errmsg);
}
