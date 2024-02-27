#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node for the binary tree
 * @parent: Pointer to the parent node
 * @value: Integer data to be inserted in the new node
 * Return: New node pointer type binary_tree or NULL on failure
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
