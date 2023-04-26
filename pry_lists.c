#include "shell.h"

/**
 * add_sep_node - adds separator found at the end
 * of a seperator list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
seperators *add_sep_node(seperators **head, char sep)
{
	seperators *new, *tmp;

	new = malloc(sizeof(seperators));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees the sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(seperators **head)
{
	seperators *tmp;
	seperators *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node - adds a command line at the end of a line_list.
 * @head: the head of the linked list.
 * @line: the command line.
 * Return: address of the head.
 */

fline_list *add_line_node(fline_list **head, char *line)
{
	fline_list *tmp, *new;

	new = malloc(sizeof(fline_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */

void free_line_list(fline_list  **head)
{
	fline_list *tmp;
	fline_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*head = NULL;
	}
}

