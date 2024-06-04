#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);
	
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	/* if the parent node has no left child */
	if (new->parent->left == NULL)
	{
		new->parent->left = new;
		return (new);
	}

	/* if the parent node has left child */

	new->left = new->parent->left; /* new node with left child of parent */
	new->parent->left->parent = new; /* shift parent of left child */
	new->parent->left = new; /* making the new node left child */

	return (new);
}
