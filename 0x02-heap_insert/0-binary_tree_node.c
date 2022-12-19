#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: Pointer to new node or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	binary_tree_t *current;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	current = parent;

	if (parent == NULL)
	{
		parent = new;
		new->parent = NULL;
		return (new);
	}

	while (current != NULL)
	{
		if (current->left == NULL)
		{
			current->left = new;
			new->parent = current;
			return (new);
		}
		if (current->right == NULL)
		{
			current->right = new;
			new->parent = current;
			return (new);
		}

		if (current->left == NULL)
			current = current->left;
		else
			current = current->right;
	}
	return (NULL);
}
