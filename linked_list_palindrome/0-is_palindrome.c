#include "lists.h"

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to head
 * Return: new head
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to head
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast;
	listint_t *first_half, *second_half, *rev_second;
	int palindrome = 1;

	if (!head || !*head || !(*head)->next)
		return (1);

	slow = fast = *head;

	/* Find middle */
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse second half */
	second_half = reverse_list(slow->next);

	/* Compare halves */
	first_half = *head;
	rev_second = second_half;
	while (rev_second)
	{
		if (first_half->n != rev_second->n)
		{
			palindrome = 0;
			break;
		}
		first_half = first_half->next;
		rev_second = rev_second->next;
	}

	/* Restore list */
	slow->next = reverse_list(second_half);

	return (palindrome);
}
