#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

void bitonic_merge(int *array, size_t size, bool up)
{
    size_t i;
    size_t step = size / 2;

    if (size < 2)
        return;

    for (i = 0; i < step; i++)
        if ((array[i] > array[i + step]) == up)
        {
            swap(&array[i], &array[i + step]);
            print_array(array, size);
        }

    bitonic_merge(array, step, up);
    bitonic_merge(array + step, step, up);
}

void bitonic_sort_rec(int *array, size_t size, bool up)
{
    size_t mid;

    if (size < 2)
        return;

    mid = size / 2;
    bitonic_sort_rec(array, mid, true);
    bitonic_sort_rec(array + mid, mid, false);
    bitonic_merge(array, size, up);
}

void bitonic_sort(int *array, size_t size)
{
    if (!array || !size)
        return;

    bitonic_sort_rec(array, size, true);
}

