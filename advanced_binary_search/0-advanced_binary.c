#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Affiche les éléments du sous-tableau
 * @array: pointeur vers le début du sous-tableau
 * @size: nombre d'éléments à afficher
 */
static void print_array(int *array, size_t size)
{
    size_t i;

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - fonction récursive interne
 * @array: pointeur vers le début du sous-tableau actuel
 * @left: index gauche (dans le tableau original)
 * @right: index droit (dans le tableau original)
 * @value: valeur à chercher
 *
 * Return: index du PREMIER occurrence, ou -1
 */
static int advanced_binary_recursive(int *array, size_t left,
                                      size_t right, int value)
{
    size_t mid;

    /* Condition d'arrêt : sous-tableau vide */
    if (left > right)
        return (-1);

    mid = left + (right - left) / 2;

    /* Affiche le sous-tableau actuel */
    print_array(array + left, right - left + 1);

    /* Si le milieu EST la valeur cherchée */
    if (array[mid] == value)
    {
        /* C'est déjà le tout premier élément du sous-tableau ? */
        if (mid == left)
            return (mid);
        /* Sinon, on cherche encore plus à gauche */
        return (advanced_binary_recursive(array, left, mid, value));
    }

    /* Valeur cherchée est à droite */
    if (array[mid] < value)
        return (advanced_binary_recursive(array, mid + 1, right, value));

    /* Valeur cherchée est à gauche */
    return (advanced_binary_recursive(array, left, mid - 1, value));
}

/**
 * advanced_binary - Point d'entrée public
 * @array: tableau trié d'entiers
 * @size: nombre d'éléments
 * @value: valeur à chercher
 *
 * Return: index du premier occurrence de value, ou -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
