#include "shell.h"

/**
 * get_len - Gets the lenght of an integer value.
 * @n: the integer value.
 * Return: Lenght of an integer.
 */
int get_len(int n)
{
	unsigned int num1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		num1 = n * -1;
	}
	else
	{
		num1 = n;
	}
	while (num1 > 9)
	{
		lenght++;
		num1 = num1 / 10;
	}

	return (lenght);
}
/**
 * a_itoa - function that converts int to string.
 * @n: the int number
 * Return: String.
 */
char *a_itoa(int n)
{
	unsigned int num1;
	int lenght = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		num1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (num1 % 10) + '0';
		num1 = num1 / 10;
		lenght--;
	}
	while (num1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, jn = 0, pn = 1, n = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				n *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		jn = jn + ((*(s + i) - 48) * n);
		n /= 10;
	}
	return (jn * pn);
}

