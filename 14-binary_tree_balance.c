#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the binary tree, 0 if tree is NULL
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}


/**
 * binary_tree_balance - Measures the balance factor of a tree
 * @tree: Pointer to the root node
 * Return: The integer factor, 0 if tree is NULL
 **/

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t fac;

	if (!tree)
		return (0);

	fac = binary_tree_height(tree->left) - binary_tree_height(tree->right);

	return ((int) fac);
}
