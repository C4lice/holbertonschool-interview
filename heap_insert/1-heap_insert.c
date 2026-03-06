#include <stdlib.h>
#include "binary_trees.h"

/**
* heap_insert - inserts a value in a Max Binary Heap
* @root: pointer to the root of the heap
* @value: value to insert
*
* Return: pointer to the inserted node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent, *queue[1024];
	int front = 0, back = 0, tmp;

	if (!root)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	queue[back++] = *root;
	while (front < back)
	{
		parent = queue[front++];

		if (!parent->left || !parent->right)
			break;

		queue[back++] = parent->left;
		queue[back++] = parent->right;
	}
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);
	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;
	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}
	return (new);
}
