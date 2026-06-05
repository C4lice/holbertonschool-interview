#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deletes an entire binary tree
 * @tree: pointer to the root of the tree
 */
void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;
    _binary_tree_delete(tree->left);
    _binary_tree_delete(tree->right);
    free(tree);
}

/**
 * new_node - Creates a new heap node
 * @parent: pointer to the parent node
 * @value: value to store
 *
 * Return: pointer to the new node, or NULL on failure
 */
static heap_t *new_node(heap_t *parent, int value)
{
    heap_t *node = malloc(sizeof(heap_t));

    if (node == NULL)
        return (NULL);
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/**
 * get_insert_parent - Finds the parent node where next insert should go
 * @root: pointer to the root
 * @size: current size of the heap
 *
 * Return: pointer to the parent node
 */
static heap_t *get_insert_parent(heap_t *root, size_t size)
{
    heap_t *queue[4096];
    int front = 0, back = 0;
    heap_t *current = NULL;

    queue[back++] = root;
    while (front < back)
    {
        current = queue[front++];
        if (current->left == NULL || current->right == NULL)
            return (current);
        queue[back++] = current->left;
        queue[back++] = current->right;
    }
    (void)size;
    return (current);
}

/**
 * _array_to_heap - Builds a Max Binary Heap from an array
 * @array: pointer to the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root of the heap, or NULL on failure
 */
heap_t *_array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;
    heap_t *parent, *node;
    int tmp;
    size_t i, heap_size;

    for (i = 0; i < size; i++)
    {
        if (root == NULL)
        {
            root = new_node(NULL, array[i]);
            if (root == NULL)
                return (NULL);
            heap_size = 1;
        }
        else
        {
            parent = get_insert_parent(root, heap_size);
            if (parent->left == NULL)
                node = new_node(parent, array[i]);
            else
                node = new_node(parent, array[i]);

            if (parent->left == NULL)
                parent->left = node;
            else
                parent->right = node;

            heap_size++;

            /* Sift up */
            while (node->parent && node->n > node->parent->n)
            {
                tmp = node->n;
                node->n = node->parent->n;
                node->parent->n = tmp;
                node = node->parent;
            }
        }
    }
    return (root);
}
