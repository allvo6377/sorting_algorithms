#include "sort.h"

/**
 * quick_sort_hoare - implementation of quick sort algorithm
 * using hoare partition scheme
 *
 * @array: the array of integers to sort
 * @size: size of the array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
    int lo = 0, hi = size - 1;

    if (array == NULL || size < 2)
        return;

    hoare_partition(array, lo, hi, size);
}

/**
 * hoare_partition - implementation of hoare partition scheme
 *
 * @array: the array of integers to sort
 * @lo: lowest index of partition
 * @hi: highest index of partition
 * @size: size of the array
 * Return: index of partition
 */

int hoare_partition(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi], tmp;
    int i = lo - 1, j = hi + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

        print_array(array, size);
    }
}


