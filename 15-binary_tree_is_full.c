#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Description: A full binary tree is a binary tree in which each node has
 * either zero or two children
 * Return: 1 if full, 0 if not or if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	left = 0;
	right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL)
		left = binary_tree_is_full(tree->left);

	if (tree->right != NULL)
		right = binary_tree_is_full(tree->right);

	return (left && right);
}
