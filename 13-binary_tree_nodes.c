#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a tree
 * @tree: Pointer to the root node of the reference tree
 * Return: The size of the node or 0 if tree is NULL
 **/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	count += (tree->left || tree->right) ? 1 : 0;
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}
