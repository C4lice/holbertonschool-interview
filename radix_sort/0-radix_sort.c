#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in an array
 * @array: The array of integers
 * @size: Number of elements in the array
 *
 * Return: The maximum value
 */
static int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts an array according to a significant digit
 * @array: The array to sort
 * @size: Number of elements in the array
 * @exp: The current digit's exponent
 *
 * Return: Nothing
 */
static void counting_sort(int *array, size_t size, int exp)
{
	int *output;
	size_t i;
	int count[10];

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	i = size;
	while (i > 0)
	{
		i--;
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using LSD radix sort
 * @array: The array to sort
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);

		if (exp > max / 10)
			break;
	}
}
