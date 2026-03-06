#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - remonte le noeud pour respecter la propriété du max heap
 * @node: noeud inséré
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
 * tree_size - retourne le nombre de noeuds
 * @tree: racine
 * Return: taille
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * insert_level - insère au bon endroit pour garder l'arbre complet
 * @root: racine
 * @node: noeud à insérer
 * @index: position
 * @size: taille
 * Return: noeud inséré
 */
heap_t *insert_level(heap_t *root, heap_t *node, size_t index, size_t size)
{
	if (index >= size)
	{
		if (!root->left)
		{
			root->left = node;
			node->parent = root;
			return (node);
		}
		else
		{
			root->right = node;
			node->parent = root;
			return (node);
		}
	}

	if (insert_level(root->left, node, index * 2 + 1, size))
		return (node);

	return (insert_level(root->right, node, index * 2 + 2, size));
}

/**
 * heap_insert - insère dans un max heap
 * @root: racine du heap
 * @value: valeur
 * Return: noeud inséré
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	size_t size;

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

	size = tree_size(*root);
	insert_level(*root, node, 0, size);

	heapify_up(node);

	return (node);
}
