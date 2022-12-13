#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number to a sorted singly linked list
 *
 * @head: first node of the list
 * @number: value for the new node
 *
 * Return: address of node, or NULL if failed
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}

	if (current->n > number)
	{
		new->next = current;
		*head = new;
		return (new);
	}

	while (current != NULL)
	{
		if (current->next->n > number || current->next == NULL)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}

	return (NULL);
}
