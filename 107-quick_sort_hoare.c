#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Orders a subset of an array of integers according to
 *                   the Hoare partition scheme (using the last element as
 *                   the pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The lower bound of the subset to order.
 * @high: The upper bound of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_rec - Implements the quicksort algorithm recursively.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * @low: The lower bound of the array partition to sort.
 * @high: The upper bound of the array partition to sort.
 */
void quick_sort_rec(int *array, size_t size, int low, int high)
{
    int p;

    if (low < high)
    {
        p = hoare_partition(array, size, low, high);
        quick_sort_rec(array, size, low, p);
        quick_sort_rec(array, size, p + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the quicksort algorithm with the Hoare partition scheme.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || !size)
        return;

    quick_sort_rec(array, size, 0, size - 1);
}

