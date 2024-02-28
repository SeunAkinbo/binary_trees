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
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root of the tree
 * Return: 1 if full, 0 otherwise
 **/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int check;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	check = (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right) &&
			(binary_tree_height(tree->left) ==
			 binary_tree_height(tree->right)));

	return (check);
}
