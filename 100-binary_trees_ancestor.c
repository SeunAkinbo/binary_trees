#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node
 *	   of two nodes, NULL if none
 **/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	if (first == second || first == second->parent ||
			second == first->parent)
		return ((binary_tree_t *) first);

	for (; first != NULL; first = first->parent)
	{
		for (temp = second; temp != NULL; temp = temp->parent)
		{
			if (first == temp)
				return ((binary_tree_t *) first);
		}
	}

	return (NULL);
}
