#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 * Return: Pointer to the root node of the created AVL, or NULL upon failure.
 **/

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i = 0, j = 0;

	if (!array)
		return (NULL);

	for (; i < size; i++)
	{
		for (; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
				return (NULL);
		}
	}
	return (root);
}
