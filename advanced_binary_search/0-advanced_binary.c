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


int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive(array, 0, size - 1, value));
}
