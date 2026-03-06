#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - maintain max heap property
 * @node: inserted node
 */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - inserts a value in a Max Binary Heap
 * @root: double pointer to root
 * @value: value to insert
 * Return: pointer to inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;
	heap_t **queue;
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!*root)
	{
		*root = node;
		return (node);
	}

	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);

	queue[rear++] = *root;

	while (front < rear)
	{
		parent = queue[front++];

		if (!parent->left)
		{
			parent->left = node;
			node->parent = parent;
			break;
		}
		else
			queue[rear++] = parent->left;

		if (!parent->right)
		{
			parent->right = node;
			node->parent = parent;
			break;
		}
		else
			queue[rear++] = parent->right;
	}

	free(queue);

	heapify_up(node);

	return (node);
}
