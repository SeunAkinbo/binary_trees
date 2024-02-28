#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Pointer to the new root
 **/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (!tree || !tree->right)
		return (tree);

	new_root = tree->right;
	tmp = new_root->left;
	new_root->left = tree;
	tree->right = tmp;
	if (tmp)
		tmp->parent = tree;

	tmp = tree->parent;
	tree->parent = new_root;
	new_root->parent = tmp;

	if (tmp)
	{
		if (tmp->left == tree)
			tmp->left = new_root;
		else
			tmp->right = new_root;
	}

	return (new_root);
}
