#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of the head of the list
 * @number: number to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *current;

    /* Allocate memory for new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    /* Case 1: empty list OR insert at beginning */
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Case 2: insert in middle or end */
    current = *head;
    while (current->next != NULL && current->next->n < number)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
