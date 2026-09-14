#include <limits.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * check_avl - Checks recursively if a tree respects BST order
 * and AVL balance rules, using min/max bounds for each node
 * @tree: pointer to the current node
 * @min: minimum value allowed for this node
 * @max: maximum value allowed for this node
 * @valid: pointer to a flag set to 0 as soon as a rule is broken
 *
 * Return: height of the subtree, or -1 if the node is NULL
 */
int check_avl(const binary_tree_t *tree, int min, int max, int *valid)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	if (tree->n < min || tree->n > max)
	{
		*valid = 0;
		return (-1);
	}

	left_height = check_avl(tree->left, min, tree->n - 1, valid);
	right_height = check_avl(tree->right, tree->n + 1, max, valid);

	if (abs(left_height - right_height) > 1)
		*valid = 0;

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int valid = 1;

	if (tree == NULL)
		return (0);

	check_avl(tree, INT_MIN, INT_MAX, &valid);

	return (valid);
}
