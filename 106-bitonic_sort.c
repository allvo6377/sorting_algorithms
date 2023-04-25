#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 0, size, 1);
}

/**
 * bitonic_sort_recursive - Recursively sorts an array of integers using
 *                          the Bitonic sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @start: Start index of the subarray to be sorted
 * @count: Count of the subarray to be sorted
 * @dir: Direction to sort in (1 = ascending, 0 = descending)
 *
 * Return: void
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start,
			    size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		bitonic_merge_recursive(array, size, start, k, dir);
		bitonic_sort_recursive(array, size, start, k, dir);
		bitonic_sort_recursive(array, size, start + k, k, !dir);
	}
}

/**
 * bitonic_merge_recursive - Recursively merges two subarrays of integers
 *                           in ascending or descending order using the
 *                           Bitonic sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @start: Start index of the first subarray to be merged
 * @count: Count of the first subarray to be merged
 * @dir: Direction to sort in (1 = ascending, 0 = descending)
 *
 * Return: void
 */
void bitonic_merge_recursive(int *array, size_t size, size_t start,
			     size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = start; i < start + k; i++)
			if ((array[i] > array[i + k]) == dir)
				swap(&array[i], &array[i + k]);

		bitonic_merge_recursive(array, size, start, k, dir);
		bitonic_merge_recursive(array, size, start + k, k, dir);
	}
}

/**
 * swap - Swaps two integers in an array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

