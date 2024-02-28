#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through the tree using level-order traversal
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a func call for each node
 **/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	const binary_tree_t *current;
	int front = 0, rear =0;

	if (!tree || !func)
		return;
	
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
		return;

	queue[rear++] = (binary_tree_t *) tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
