#include "sort.h"

/**
 * partition - partitions an array using the Lomuto scheme
 * @array: pointer to the array to sort
 * @size: size of the array
 * @low: lower index of the partition
 * @high: higher index of the partition
 * Return: the final partition index
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm recursively
 * @array: pointer to the array to sort
 * @size: size of the array
 * @low: lower index of the partition
 * @high: higher index of the partition
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		quicksort(array, size, low, pi - 1);
		quicksort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}

