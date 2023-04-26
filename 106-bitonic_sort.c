#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * print_array - prints an array of integers
 * @arr: the array to be printed
 * @n: the size of the array
 */
void print_array(int arr[], size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/**
 * bitonic_compare - compares and swaps elements in a bitonic sequence
 * @arr: the array of integers
 * @low: the starting index of the sequence
 * @cnt: the length of the sequence
 * @dir: the direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_compare(int arr[], size_t low, size_t cnt, int dir)
{
	size_t i, k;

	k = cnt / 2;
	for (i = low; i < low + k; i++)
	{
		/* dir = 1 means sort in ascending order */
		/* dir = 0 means sort in descending order */
		if (dir == (arr[i] > arr[i + k]))
		{
			swap(&arr[i], &arr[i + k]);
			print_array(arr, cnt);
		}
	}
}

/**
 * bitonic_merge - merges two bitonic sequences into one
 * @arr: the array of integers
 * @low: the starting index of the first sequence
 * @cnt: the length of each sequence
 * @dir: the direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int arr[], size_t low, size_t cnt, int dir)
{
	if (cnt > 1)
	{
		/* compare and swap elements in a bitonic sequence */
		bitonic_compare(arr, low, cnt, dir);
		/* recursively sort the two halves of the bitonic sequence */
		bitonic_merge(arr, low, cnt / 2, dir);
		bitonic_merge(arr, low + cnt / 2, cnt / 2, dir);
	}
}

/**
 * bitonic_sort - sorts a bitonic sequence using recursion
 * @arr: the array of integers
 * @low: the starting index of the sequence
 * @cnt: the length of the sequence
 * @dir: the direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort(int arr[], size_t low, size_t cnt, int dir)
{
	if (cnt > 1)
	{
		/* recursively generate a bitonic sequence of length cnt/2 */
		/* with opposite sorting directions */
		bitonic_sort(arr, low, cnt / 2, 1);
		bitonic_sort(arr, low + cnt / 2, cnt / 2, 0);

		/* merge the two bitonic sequences */
		bitonic_merge(arr, low, cnt, dir);
	}
}
