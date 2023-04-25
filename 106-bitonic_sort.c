#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: pointer to the array
 * @size: size of the array
 * @a: index of the first element
 * @b: index of the second element
 */
void swap(int *array, size_t size, size_t a, size_t b)
{
	int tmp;

	if (a == b)
		return;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

/**
 * bitonic_compare - compares and swaps elements in a bitonic sequence
 * @array: pointer to the array
 * @size: size of the array
 * @low: lower index of the sequence
 * @count: number of elements in the sequence
 * @dir: direction of sorting (1 for up, 0 for down)
 */
void bitonic_compare(int *array, size_t size,
		     size_t low, size_t count, int dir)
{
	size_t i, k;

	k = count / 2;
	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
			swap(array, size, i, i + k);
	}
}

/**
 * bitonic_merge - recursively sorts a bitonic sequence in a given direction
 * @array: pointer to the array
 * @size: size of the array
 * @low: lower index of the sequence
 * @count: number of elements in the sequence
 * @dir: direction of sorting (1 for up, 0 for down)
 */
void bitonic_merge(int *array, size_t size,
		   size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		bitonic_compare(array, size, low, count, dir);
		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_sort_rec - recursively produces a bitonic sequence and sorts it
 * @array: pointer to the array to sort
 * @size: size of the array
 * @low: lower index of the current sequence
 * @count: number of elements in the current sequence
 * @dir: direction of sorting (1 for up, 0 for down)
 */
void bitonic_sort_rec(int *array, size_t size,
		      size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%lu/%lu] (%s):\n", count,
		       size, dir ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_sort_rec(array, size, low, k, 1);
		bitonic_sort_rec(array, size, low + k, k, 0);
		printf("Result [%lu/%lu] (%s):\n", count,
		       size, dir ? "UP" : "DOWN");
		bitonic_merge(array, size, low, count,
			      dir);
		print_array(array + low,
			    count);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array,
		  size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_rec(array,
			 size,
			 0,
			 size,
			 1);
}

