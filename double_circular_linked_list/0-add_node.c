#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Allocates and initializes a new List node
 * @str: The string to duplicate into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *node;

	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	node->prev = node;
	node->next = node;

	return (node);
}

/**
 * add_node_end - Adds a new node to the end of a doubly
 *                circular linked list
 * @list: A pointer to the head of the list
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node;
	List *tail;

	if (list == NULL || str == NULL)
		return (NULL);

	node = create_node(str);
	if (node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		*list = node;
		return (node);
	}

	tail = (*list)->prev;

	node->next = *list;
	node->prev = tail;
	tail->next = node;
	(*list)->prev = node;

	return (node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a doubly
 *                  circular linked list
 * @list: A pointer to the head of the list
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;
	List *tail;

	if (list == NULL || str == NULL)
		return (NULL);

	node = create_node(str);
	if (node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		*list = node;
		return (node);
	}

	tail = (*list)->prev;

	node->next = *list;
	node->prev = tail;
	tail->next = node;
	(*list)->prev = node;
	*list = node;

	return (node);
}
