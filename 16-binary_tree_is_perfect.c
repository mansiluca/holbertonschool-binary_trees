#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, int depth, int level);

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Description: A perfect binary tree is a binary tree in which all
 * leaves are at the same depth, and in which every parent has two children
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int depth = binary_tree_depth(tree);

	return (is_perfect(tree, depth, 0));
}

/**
 * binary_tree_depth - function that measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 * Return: depth of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect - helper function to check if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: depth of the tree
 * @level: current level in the tree
 * Return: 1 if perfect, 0 otherwise
 */

int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		   is_perfect(tree->right, depth, level + 1));
}
