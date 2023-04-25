#include "sort.h"

/**
 * get_max - gets the maximum value in an array of integers
 * @array: pointer to the array
 * @size: size of the array
 * Return: the maximum value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - sorts an array of integers in ascending order
 * using the Counting sort algorithm for a specific digit
 * @array: pointer to the array to sort
 * @size: size of the array
 * @exp: exponent representing the current digit
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *count, *output;
	size_t i;
	int max, digit;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}

