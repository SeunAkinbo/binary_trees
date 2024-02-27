#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node at the right-child of other node
 * @parent: Pointer to the node to insert the right-child
 * @value: Integer value to be stored in the new node
 * Return: Pointer to the new node, or NULL on failure, or if parent is NULL
 **/


binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_newnode;

	if (!parent)
		return (NULL);

	right_newnode = binary_tree_node(parent, value);
	if (!right_newnode)
		return (NULL);

	if (parent->right)
	{
		right_newnode->right = parent->right;
		parent->right->parent = right_newnode;
	}

	parent->right = right_newnode;

	return (right_newnode);
}
