#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert left-child
 * @value: Integer value to be stored in the new node
 * Return: Pointer to the newnode or NULL on failure or if parent is NULL
 **/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_newnode;

	if (!parent)
		return (NULL);

	left_newnode = binary_tree_node(parent, value);
	if (!left_newnode)
		return (NULL);

	if (parent->left)
	{
		left_newnode->left = parent->left;
		parent->left->parent = left_newnode;
	}

	parent->left = left_newnode;

	return (left_newnode);
}
