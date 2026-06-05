#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Counts the number of nodes in a binary tree
 * @root: pointer to the root node
 *
 * Return: number of nodes
 */
static size_t heap_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * get_last_node - Gets the last node in level-order
 * @root: pointer to the root node
 * @size: total number of nodes in the heap
 *
 * Return: pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t size)
{
	heap_t *queue[4096];
	heap_t *current;
	int front;
	int back;

	if (root == NULL)
		return (NULL);

	front = 0;
	back = 0;
	queue[back++] = root;

	while (front < back)
	{
		current = queue[front++];
		if (current->left)
			queue[back++] = current->left;
		if (current->right)
			queue[back++] = current->right;
	}
	(void)size;
	return (current);
}

/**
 * sift_down - Restores the Max Heap property by pushing a node downward
 * @root: pointer to the node to sift down
 */
static void sift_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	while (root != NULL)
	{
		largest = root;

		/* Cherche le plus grand entre root, enfant gauche et enfant droit */
		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		/* Si root est déjà le plus grand, c'est terminé */
		if (largest == root)
			break;

		/* Échange les valeurs */
		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;

		/* Continue vers le bas */
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last;
	size_t size;

	if (root == NULL || *root == NULL)
		return (0);

	/* 1. Sauvegarde la valeur de la racine */
	value = (*root)->n;

	/* 2. Cas spécial : un seul nœud */
	size = heap_size(*root);
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* 3. Trouve le dernier nœud level-order */
	last = get_last_node(*root, size);

	/* 4. Copie la valeur du dernier nœud dans la racine */
	(*root)->n = last->n;

	/* 5. Supprime le dernier nœud */
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	free(last);

	/* 6. Reconstruit le heap (sift down depuis la racine) */
	sift_down(*root);

	return (value);
}
