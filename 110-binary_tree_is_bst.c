#include "binary_trees.h"

/**
 * inorder_traversal - Helper function for inorder traversal of a binary tree
 * @tree: Pointer to the root node of the tree
 * @prev_value: Pointer to the value of the previous node
 * Return: True if inorder traversal is successful and the tree is a BST,
 *         false otherwise
 **/

bool inorder_traversal(const binary_tree_t *tree, int *prev_value)
{
	if (tree == NULL)
		return (true);

	/* Traverse the left subtree */
	if (!inorder_traversal(tree->left, prev_value))
		return (false);

	if (*prev_value >= tree->n)
		return (false);

	/* Update the previous value with the current node's value */
	*prev_value = tree->n;

	/* Traverse the right subtree */
	return (inorder_traversal(tree->right, prev_value));
}

/**
 * binary_tree_is_bst - Checks if a binary tree
 *			is a valid Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 **/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value = INT_MIN;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Perform inorder traversal and check if the tree is a valid BST */
	if (inorder_traversal(tree, &prev_value))
		return (1);
	else
		return (0);
}
