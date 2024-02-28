#include "binary_trees.h"

/**
 * bst_free - Frees a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to free
 **/
void bst_free(bst_t *tree)
{
	if (!tree)
		return;

	bst_free(tree->left);
	bst_free(tree->right);
	free(tree);
}

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 **/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			/* Insertion failed, clean up and return NULL */
			bst_free(root);
			return (NULL);
		}
	}

	return (root);
}
