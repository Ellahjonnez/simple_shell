#include "shell.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a var_list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */

var_list *add_rvar_node(var_list **head, int lvar, char *val, int lval)
{
	var_list *new, *tmp;

	new = malloc(sizeof(var_list));
	if (new == NULL)
		return (NULL);

	new->len_variable = lvar;
	new->value = val;
	new->len_value = lval;

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
 * free_var_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_var_list(var_list **head)
{
	var_list *tmp;
	var_list *curr;

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

