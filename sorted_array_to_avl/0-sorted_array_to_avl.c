#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - crée un noeud AVL
 * @parent: parent du noeud
 * @value: valeur du noeud
 *
 * Return: pointeur vers le noeud
 */
avl_t *create_node(avl_t *parent, int value)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (!node)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/**
 * build_avl - construit récursivement l'arbre
 * @array: tableau
 * @start: début
 * @end: fin
 * @parent: parent du noeud
 *
 * Return: racine du sous-arbre
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
    int mid;
    avl_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    root = create_node(parent, array[mid]);
    if (!root)
        return (NULL);

    root->left = build_avl(array, start, mid - 1, root);
    root->right = build_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - construit un AVL depuis un tableau trié
 * @array: tableau trié
 * @size: taille
 *
 * Return: racine de l'AVL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl(array, 0, size - 1, NULL));
}
