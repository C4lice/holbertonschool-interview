#include <stdio.h>
#include <math.h>
#include "search.h"
 
/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev;
	skiplist_t *express;
 
	if (!list)
		return (NULL);
 
	prev = list;
	express = list;
 
	/* ETAPE 1 : parcourir la voie express */
	while (express->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->express->index, express->express->n);
 
		if (express->express->n >= value)
			break;
 
		prev = express->express;
		express = express->express;
	}
 
	/* Afficher l'intervalle trouve */
	if (express->express != NULL)
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, express->express->index);
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, express->index);
 
	/* ETAPE 2 : chercher pas a pas dans l'intervalle */
	while (prev != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);
 
		if (prev->n == value)
			return (prev);
 
		if (prev->n > value)
			return (NULL);
 
		if (express->express != NULL &&
			prev->index >= express->express->index)
			return (NULL);
 
		prev = prev->next;
	}
 
	return (NULL);
}
