#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 **/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	const binary_tree_t *current;
	int front = 0, rear = 0;
	int empty_node = 0;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
		return (0);

	queue[rear++] = (binary_tree_t *) tree;

	while (front < rear)
	{
		current = queue[front++];

		if (empty_node && (current->left && current->right))
		{
			free(queue);
			return (0);
		}

		if (current->right && !current->left)
		{
			free(queue);
			return (0);
		}

		if (current->left)
			queue[rear++] = current->left;
		else
			empty_node = 1;

		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
	return (1);
}
