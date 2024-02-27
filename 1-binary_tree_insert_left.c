#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert left-child
 * @value: Integer value to be stored in the new node
 * Return: Pointer to the newnode or NULL on failure or if parent is NULL
 **/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode, *temp;

	if (parent == NULL)
		return (NULL);

	newnode = binary_tree_node(parent, value);
	if (newnode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		temp = parent->left;
		parent->left = newnode;
		newnode->left = temp;
	}
	else
		parent->left = newnode;

	return (parent);
}
