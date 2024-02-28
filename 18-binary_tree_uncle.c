#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of the node
 * @node: Pointer to the node to find the uncle
 * Return: Pointer to the uncle, NULL otherwise
 **/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);

	return (NULL);
}
