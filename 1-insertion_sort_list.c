#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1 == node2)
        return;

    if (node1->next == node2)
    {
        node1->next = node2->next;
        if (node2->next != NULL)
            node2->next->prev = node1;
        node2->prev = node1->prev;
        if (node1->prev != NULL)
            node1->prev->next = node2;
        else
            *list = node2;
        node2->next = node1;
        node1->prev = node2;
    }
    else
    {
        listint_t *tmp = node1->prev;
        node1->prev = node2->prev;
        if (node2->prev != NULL)
            node2->prev->next = node1;
        else
            *list = node1;
        node2->prev = tmp;
        if (tmp != NULL)
            tmp->next = node2;

        tmp = node1->next;
        node1->next = node2->next;
        if (node2->next != NULL)
            node2->next->prev = node1;
        node2->next = tmp;
        tmp->prev = node2;
    }
    print_list(*list);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        insert = current;
        while (insert->prev != NULL && insert->n < insert->prev->n)
        {
            swap_nodes(list, insert->prev, insert);
            insert = insert->prev;
        }
        current = current->next;
    }
}
