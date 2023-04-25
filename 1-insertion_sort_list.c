#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node: pointer to the node to swap with the next node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *tmp;

	tmp = node->next;
	if (node->prev)
		node->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = node->prev;
	node->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = node;
	tmp->next = node;
	node->prev = tmp;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (!list || !(*list) || !(*list)->next)
		return;
	curr = (*list)->next;
	while (curr)
	{
		prev = curr->prev;
		while (prev && prev->n > curr->n)
		{
			swap_nodes(list, prev);
			print_list((const listint_t *)*list);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}

