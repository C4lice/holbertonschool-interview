#include "binary_trees.h"

/**
 * create_node - create a node
 *
 * @value: Value to put
 *
 * Return: the node on success, NULL on failure
 */
avl_t *create_node(int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return (node);
}

/**
 * build_avl - build the AVL
 *
 * @array: The array to be transform
 * @start: start of the array to AVL
 * @end: end of the array to AVL$
 *
 * Return: the head on success, NULL on failure
 */
static avl_t *build_avl(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = create_node(array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(array, start, mid - 1);
	if (root->left)
		root->left->parent = root;

	root->right = build_avl(array, mid + 1, end);
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - Sorted an array into an AVL
 *
 * @array: The array to be Sorted
 * @size: Size of the array
 *
 * Return: the head on success, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1));
}
