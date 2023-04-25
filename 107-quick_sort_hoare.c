#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

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

void quick_sort_hoare(int *array, size_t size)
{
    if (!array || !size)
        return;

    quick_sort_rec(array, size, 0, size - 1);
}

