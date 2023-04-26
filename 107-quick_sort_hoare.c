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
 * hoare_partition - partitions an array using Hoare scheme
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 * Return: final partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(array, size, i, j);
	}
}

/**
 * quick_sort_hoare_rec - recursively sorts an array using quick sort with Hoare scheme
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 */
void quick_sort_hoare_rec(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, size, low, high);
		quick_sort_hoare_rec(array, size, low, p);
		quick_sort_hoare_rec(array, size, p + 1, high);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using quick sort with Hoare scheme
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort_hoare(int *array,
		      size_t size)
{
	if (!array || !size)
		return;
	quick_sort_hoare_rec(array,
			     size,
			     0,
			     size - 1);
}
