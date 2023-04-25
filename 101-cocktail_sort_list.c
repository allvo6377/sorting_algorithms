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
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = *list;
		while (curr && curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		curr = curr->prev;
		while (curr && curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}

