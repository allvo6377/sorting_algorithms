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
 * sift_down - repairs the heap whose root element is at index start
 * @array: pointer to the array
 * @size: size of the array
 * @start: root index
 * @end: last index of the heap
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child;

	root = start;
	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(array, size, root, child);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - creates a heap from an unsorted array
 * @array: pointer to the array
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start;

	start = (size - 2) / 2;
	while (1)
	{
		sift_down(array, size, start, size - 1);
		if (start == 0)
			break;
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, end, 0);
		end--;
		sift_down(array, size, 0, end);
	}
}

