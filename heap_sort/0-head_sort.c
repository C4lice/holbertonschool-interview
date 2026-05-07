#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
static void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Sifts down an element in a heap
 * @array: The array representing the heap
 * @size: The full size of the array
 * @root: Index of the root of the subtree to sift down
 * @end: The last valid index of the heap portion
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest;
	size_t left;
	size_t right;

	while (1)
	{
		largest = root;
		left = 2 * root + 1;
		right = 2 * root + 2;

		if (left <= end && array[left] > array[largest])
			largest = left;

		if (right <= end && array[right] > array[largest])
			largest = right;

		if (largest == root)
			break;

		swap(&array[root], &array[largest]);
		print_array(array, size);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the heap sort algorithm (sift-down)
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int i;

	if (!array || size < 2)
		return;

	/* Build max heap */
	i = (int)(size / 2) - 1;
	while (i >= 0)
	{
		sift_down(array, size, (size_t)i, size - 1);
		i--;
	}

	/* Extract elements one by one */
	end = size - 1;
	while (end > 0)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
