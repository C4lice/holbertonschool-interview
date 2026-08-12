#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_sub_array - Prints a portion of an array separated by ", "
 * @array: The array to print
 * @left: Index of the first element to print
 * @right: Index right after the last element to print (exclusive)
 */
static void print_sub_array(const int *array, size_t left, size_t right)
{
	size_t i;

	for (i = left; i < right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * merge - Merges two sorted halves of array[left..right) using buffer
 * @array: The original array (also where the merged result is written back)
 * @buffer: Temporary working area (already allocated once by merge_sort)
 * @left: Start index of the left half
 * @middle: Start index of the right half (end of the left half)
 * @right: Index right after the last element of the right half
 */
static void merge(int *array, int *buffer, size_t left, size_t middle,
		size_t right)
{
	size_t i = left, j = middle, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_sub_array(array, left, middle);
	printf("[right]: ");
	print_sub_array(array, middle, right);

	while (i < middle && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}
	while (i < middle)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_sub_array(array, left, right);
}

/**
 * top_down_merge_sort - Recursively sorts array[left..right) using buffer
 * @array: The array being sorted
 * @buffer: Shared temporary working area
 * @left: Start index of the range to sort
 * @right: Index right after the last element of the range to sort
 */
static void top_down_merge_sort(int *array, int *buffer, size_t left,
		size_t right)
{
	size_t middle;

	if (right - left < 2)
		return;

	middle = left + (right - left) / 2;

	top_down_merge_sort(array, buffer, left, middle);
	top_down_merge_sort(array, buffer, middle, right);
	merge(array, buffer, left, middle, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the top-down Merge Sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	top_down_merge_sort(array, buffer, 0, size);

	free(buffer);
}
