#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 **/

void create_tree(avl_t **node, int *array, size_t start, size_t end)
{
	size_t middle;

	if (start > end)
		return;

	middle = (start + end) / 2;

	(*node) = binary_tree_node(NULL, array[middle]);

	create_tree(&((*node)->left), array, start, middle - 1);
	create_tree(&((*node)->right), array, middle + 1, end);
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 **/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t middle;
	avl_t *root, **nodes;

	if (size == 0)
		return (NULL);

	middle = (size - 1) / 2;
	nodes = malloc(size * sizeof(avl_t *));
	if (!nodes)
		return (NULL);

	for (size_t i = 0; i < size; i++)
		nodes[i] = binary_tree_node(NULL, array[i]);

	for (size_t i = 0; i < size; i++)
	{
		if (2 * i + 1 < size)
			nodes[i]->left = nodes[2 * i + 1];
		if (2 * i + 2 < size)
			nodes[i]->right = nodes[2 * i + 2];
	}

	root = nodes[middle];
	free(nodes);

	return (root);
}
