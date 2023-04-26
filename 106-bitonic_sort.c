#include "sort.h"

/**
 * swap - swaps two elements in an array and prints the array
 * @array: pointer to the array
 * @size: size of the array
 * @i: index of the first element
 * @j: index of the second element
 */
void swap(int *array, size_t size, size_t i, size_t j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * bitonic_compare - compares and swaps elements in a bitonic sequence
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of the sequence
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
 * @low: starting index of the sequence
 * @count: number of elements in the sequence
 * @dir: direction of sorting (1 for up, 0 for down)
 */
void bitonic_merge(int *array, size_t size,
		   size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		bitonic_compare(array, size, low, count, dir);
		bitonic_merge(array, size, low, count / 2, dir);
		bitonic_merge(array, size, low + count / 2,
			      count / 2, dir);
	}
}

/**
 * bitonic_sort_rec - recursively produces a bitonic sequence and sorts it
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of the sequence
 * @count: number of elements in the sequence
 * @dir: direction of sorting (1 for up, 0 for down)
 */
void bitonic_sort_rec(int *array, size_t size,
		      size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", count,
		       size,
		       dir ? "UP" : "DOWN");
		print_array(array + low,
			    count);
		bitonic_sort_rec(array,
				 size,
				 low,
				 count / 2,
				 1);
		bitonic_sort_rec(array,
				 size,
				 low + count / 2,
				 count / 2,
				 0);
		printf("Result [%lu/%lu] (%s):\n", count,
		       size,
		       dir ? "UP" : "DOWN");
		bitonic_merge(array,
			      size,
			      low,
			      count,
			      dir);
		print_array(array + low,
			    count);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using Bitonic
 * @array: pointer to the array
 * @size: size of the array
 */
void bitonic_sort(int *array,
		  size_t size)
{
	if (!array || !size)
		return;
	bitonic_sort_rec(array,
			 size,
			 0,
			 size,
			 1);
}
