#include <stdio.h>
#include <math.h>
#include "search.h"
 
/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *node;
 
	if (!list)
		return (NULL);
 
	express = list;
 
	/* Phase 1: traverse the express lane */
	while (express->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->express->index, express->express->n);
 
		if (express->express->n >= value)
			break;
 
		express = express->express;
	}
 
	/* express is now just before the range, express->express is the upper bound */
	printf("Value found between indexes [%lu] and [%lu]\n",
		express->index,
		express->express ? express->express->index : express->index);
 
	/* Phase 2: linear search between express and express->express */
	node = express;
	while (node && (express->express == NULL || node->index <= express->express->index))
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
 
		if (node->n == value)
			return (node);
 
		node = node->next;
	}
 
	return (NULL);
}
