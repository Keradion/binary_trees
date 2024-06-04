#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * * @value: the value to store in the new node
 *
 * Return: new node address or NULL if it fails or parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (parent == NULL)
	{
		free(new);
		return (NULL);
	}

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	/* if the parent has no right-child */

	if (parent->right == NULL)
	{
		parent->right = new;
		return (new);
	}

	/* if the parent has a right-child */

	new->right = parent->right;
	parent->right->parent = new;
	parent->right = new;

	return (new);
}
