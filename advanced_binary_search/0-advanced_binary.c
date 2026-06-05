#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"


/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	printf("Searching in array: ");
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/** recursive - Recursive function to perform the advanced binary search
 * @array: The array to be searched
 * @left: The left index of the current search range
 * @right: The right index of the current search range
 * @value: The value to search for
 * Return: The index of the first occurrence of @value in @array, or -1 if not found
 */
int recursive(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array + left, right - left + 1);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);

		return (recursive(array, left, mid, value));
	}

	if (array[mid] < value)
		return (recursive(array, mid + 1, right, value));

	return (recursive(array, left, mid, value));
}

/** advanced_binary - Searches for a value in a sorted array of integers using
 * the Advanced Binary search algorithm
 * @array: The array to be searched
 * @size: The number of elements in @array
 * @value: The value to search for
 * Return: The index of the first occurrence of @value in @array, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive(array, 0, size - 1, value));
}
