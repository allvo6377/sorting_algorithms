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
 * hoare_partition - partitions an array using Hoare scheme
 * @arr: the array to be partitioned
 * @low: the lowest index of the subarray
 * @high: the highest index of the subarray
 * Return: the final partition index
 */
int hoare_partition(int arr[], int low, int high)
{
	int pivot = arr[high]; /* pivot */
	int i = low - 1; /* index of smaller element */
	int j;

	for (j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than or equal to pivot */
		if (arr[j] <= pivot)
		{
			i++; /* increment index of smaller element */
			swap(&arr[i], &arr[j]); /* swap current element with index */
			print_array(arr, high - low + 1); /* print the array after swapping */
		}
	}
	swap(&arr[i + 1], &arr[high]); /* swap pivot with index */
	print_array(arr, high - low + 1); /* print the array after swapping */
	return (i + 1); /* return the partition index */
}

/**
 * quick_sort_hoare - sorts an array using Quick sort algorithm
 * @arr: the array to be sorted
 * @low: the lowest index of the subarray
 * @high: the highest index of the subarray
 */
void quick_sort_hoare(int arr[], size_t low, size_t high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now at right place */
		size_t pi = hoare_partition(arr, low, high);

		/* Recursively sort elements before and after partition */
		quick_sort_hoare(arr, low, pi - 1);
		quick_sort_hoare(arr, pi + 1, high);
	}
}

/**
 * main - driver program to test above functions
 * Return: always 0
 */
int main(void)
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	size_t n = sizeof(arr) / sizeof(arr[0]);

	quick_sort_hoare(arr, 0, n - 1);
	printf("Sorted array: \n");
	print_array(arr, n);
	return (0);
}
