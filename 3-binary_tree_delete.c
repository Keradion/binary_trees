#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 * if tree is NULL do nothing
 *
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *root = tree;

	if (tree == NULL)
		return;

	binary_tree_delete(root->left);
	binary_tree_delete(root->right);
	free(root);

}
