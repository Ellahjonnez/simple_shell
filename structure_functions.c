#include "shell.h"

/**
 * _strcat - to concatenate two strings
 * @dest: the char pointer to the dest of the copied str
 * @src: const char pointer of the source of str
 * Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: The char pointer to the dest of the copied str
 * @src: The char pointer to the source of str
 * Return: dest.
 */

char *_strcpy(char *dest, char *src)
{
	size_t n;

	for (n = 0; src[n] != '\0'; n++)
	{
		dest[n] = src[n];
	}
	dest[n] = '\0';

	return (dest);
}
/**
 * _strcmp - A function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strchr - locates a character in a string,
 * @s: the string.
 * @c: the character.
 * Return: the pointer to the first occurrence of the character c.
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: the initial segment.
 * @accept: the accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, j;
	int bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

