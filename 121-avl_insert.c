#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, otherwise 0 if tree is NULL
 **/

size_t height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) : 1;
	right_height = tree->right ? binary_tree_height(tree->right) : 1;
	return ((left_height > right_height) ? left_height : right_height);
}


/**
 * balance - Measures the balance factor of a tree
 * @tree: Pointer to the root node
 * Return: The integer factor, 0 if tree is NULL
 **/

int balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((height(tree->left) - height(tree->right)));
}


/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: Pointer to the root node of the AVL tree to insert into.
 * @parent: Parent node of the current working node.
 * @new: Pointer to store the new node.
 * @value: Value to insert into the AVL tree.
 * Return: Pointer to the new root after insertion, or NULL on failure.
 **/

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfac;

	if (!(*tree))
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	bfac = balance(*tree);
	if (bfac > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfac < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfac > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfac < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}


/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree to insert into.
 * @value: Value to insert into the AVL tree.
 * Return: Pointer to the inserted node, or NULL on failure.
 **/

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
