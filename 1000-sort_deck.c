#include "deck.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
void swap_nodes(deck_node_t **a, deck_node_t **b)
{
	deck_node_t *prev_a = (*a)->prev;
	deck_node_t *next_b = (*b)->next;

	if (prev_a)
		prev_a->next = *b;
	if (next_b)
		next_b->prev = *a;
	(*a)->next = next_b;
	(*a)->prev = *b;
	(*b)->next = *a;
	(*b)->prev = prev_a;
}

/**
 * compare_cards - compares two cards by value and kind
 * @a: pointer to the first card
 * @b: pointer to the second card
 * Return: 1 if a > b, 0 if a == b, -1 if a < b
 */
int compare_cards(const card_t *a, const card_t *b)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			  "10", "Jack", "Queen", "King"};
	int i, j;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(a->value, values[i]) == 0)
			break;
	}
	for (j = 0; j < 13; j++)
	{
		if (strcmp(b->value, values[j]) == 0)
			break;
	}
	if (i > j)
		return (1);
	if (i < j)
		return (-1);
	if (a->kind > b->kind)
		return (1);
	if (a->kind < b->kind)
		return (-1);
	return (0);
}

/**
 * insertion_sort_list - sorts a doubly linked list of cards
 * @list: pointer to the head of the list
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *curr, *insert, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		insert = curr;
		temp = curr->next;
		while (insert->prev && compare_cards(insert->card, insert->prev->card) < 0)
		{
			swap_nodes(&(insert->prev), &insert);
			if (!insert->prev)
				*list = insert;
			print_deck(*list);
		}
		curr = temp;
	}
}
