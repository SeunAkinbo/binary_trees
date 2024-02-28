#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 **/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current, *parent;

	if (!tree)
		return (NULL);

	current = *tree;
	parent = NULL;

	while (current)
	{
		parent = current;

		/* If the value is already present in the tree, ignore it */
		if (value == current->n)
			return (NULL);

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	/* Create the new node */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (new_node);

	/* Insert the new node as a child of the appropriate parent */
	if (!parent)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

