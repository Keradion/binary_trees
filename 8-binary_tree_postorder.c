#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using pre-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp = tree;

	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(temp->left, func);
	binary_tree_postorder(temp->right, func);
	func(temp->n);
}
