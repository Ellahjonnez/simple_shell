#include "shell.h"

/**
 * _strdup - duplicates a string in the heap memory.
 * @s: The char pointer to the string
 * Return: duplicated string
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: The char pointer to the string
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compares the chars of strings
 * @str: the input string.
 * @delim: delimiter.
 * Return: 1 if is equal, 0 if not.
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: the input string.
 * @delim: delimiter.
 * Return: string splited.
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted_str, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted_str = str; /*to store the first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Stores the last address*/
	}
	str_start = splitted_str;
	if (str_start == str_end) /*Reaches end of a str*/
		return (NULL);

	for (bool = 0; *splitted_str; splitted_str++)
	{
		/*Breaking loop to find the next token*/
		if (splitted_str != str_start)
			if (*splitted_str && *(splitted_str - 1) == '\0')
				break;
		/*Replacing delimiter with the null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted_str == delim[i])
			{
				*splitted_str = '\0';
				if (splitted_str == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted_str) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - checks if the string passed is a number
 * @s: the input string
 * Return: 1 if string is a number. Else return 0.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
