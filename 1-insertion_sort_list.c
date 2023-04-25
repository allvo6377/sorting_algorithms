#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *curr = *list, *next = NULL;

        while (curr != NULL)
        {
                next = curr->next;

                while (curr->prev != NULL && curr->prev->n > curr->n)
                {
                        curr->prev->next = curr->next;

                        if (curr->next != NULL)
                                curr->next->prev = curr->prev;

                        curr->next = curr->prev;
                        curr->prev = curr->prev->prev;
                        curr->next->prev = curr;

                        if (curr->prev == NULL)
                                *list = curr;

                        print_list(*list);
                }

                curr = next;
        }
}

