#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: double pointer to the root node of the Heap
 * @value: value to put in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *current;

	if (!root)
		return (binary_tree_node((*root), value));

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (new);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	current = *root;

	while (current != NULL)
	{
		if (current->n > value)
		{
			if (_height(current->left) <= 1 && _height(current->right) <= 1)
			{
				if (_height(current->left) > _height(current->right))
				{
					current->right = new;
					new->parent = current;
				}
				else
				{
					current->left = new;
					new->parent = current;
				}
				return (new);
			}
		}
		else
			return (heap_insert_atop(new, current));

		if (_height(current->left) > _height(current->right))
			current = current->right;
		else
			current = current->left;
	}

	return (new);
}

heap_t *heap_insert_atop(heap_t *big, heap_t *low)
{
	if (!big || !low)
		return (NULL);

	big->parent = low->parent;
	low->parent = big;

	if (_height(low->left) > _height(low->right))
	{
		big->right = low;
		big->left = low->left;
		if (low->left != NULL)
			low->left->parent = big;
	}
	else
	{
		big->left = low;
		big->right = low->right;
		if (low->right != NULL)
			low->right->parent = big;
	}
	return (big);
}
