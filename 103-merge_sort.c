#include "sort.h"

/**
 * merge - merges two subarrays of integers
 * @array: pointer to the array to sort
 * @size: size of the array
 * @left: pointer to the left subarray
 * @right: pointer to the right subarray
 * @middle: middle index of the array
 */
void merge(int *array, size_t size, int *left, int *right, size_t middle)
{
	size_t i, j, k;

	i = j = k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, middle);
	printf("[right]: ");
	print_array(right, size - middle);
	while (i < middle && j < size - middle)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < middle)
		array[k++] = left[i++];
	while (j < size - middle)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle, i;
	int left[300], right[300];

	if (!array || size < 2)
		return;
	middle = size / 2;
	for (i = 0; i < middle; i++)
		left[i] = array[i];
	for (i = middle; i < size; i++)
		right[i - middle] = array[i];
	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, size, left, right, middle);
}

