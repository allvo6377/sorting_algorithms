#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - compares two cards by value and kind
 * @a: pointer to the first card
 * @b: pointer to the second card
 * Return: negative if a < b, zero if a == b, positive if a > b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = *(const card_t **)a;
	const card_t *card_b = *(const card_t **)b;
	int value_a, value_b;

	/* convert card values to integers for comparison */
	if (card_a->value[0] == 'A')
		value_a = 1;
	else if (card_a->value[0] == 'J')
		value_a = 11;
	else if (card_a->value[0] == 'Q')
		value_a = 12;
	else if (card_a->value[0] == 'K')
		value_a = 13;
	else
		value_a = atoi(card_a->value);

	if (card_b->value[0] == 'A')
		value_b = 1;
	else if (card_b->value[0] == 'J')
		value_b = 11;
	else if (card_b->value[0] == 'Q')
		value_b = 12;
	else if (card_b->value[0] == 'K')
		value_b = 13;
	else
		value_b = atoi(card_b->value);

	/* compare cards by value and kind */
	if (value_a != value_b)
		return (value_a - value_b);
	return (card_a->kind - card_b->kind);
}

/**
 * count_deck - counts the number of nodes in the deck
 * @deck: pointer to the head of the doubly linked list
 * Return: number of nodes in the deck
 */
size_t count_deck(deck_node_t **deck)
{
	deck_node_t *node = NULL;
	size_t size = 0;

	node = *deck;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

/**
 * create_array - creates an array of pointers to the cards
 * @deck: pointer to the head of the doubly linked list
 * @size: size of the array
 * Return: pointer to the array or NULL on failure
 */
const card_t **create_array(deck_node_t **deck, size_t size)
{
	const card_t **array = NULL;
	deck_node_t *node = NULL;
	size_t i = 0;

	array = malloc(sizeof(card_t *) * size);
	if (!array)
		return (NULL);

	node = *deck;
	while (node)
	{
		array[i++] = node->card;
		node = node->next;
	}
	return (array);
}

/**
 * update_deck - updates the deck with the sorted array
 * @deck: pointer to the head of the doubly linked list
 * @array: pointer to the array of pointers to cards
 * @size: size of the array and deck
 */
void update_deck(deck_node_t **deck, const card_t **array, size_t size)
{
	deck_node_t *node = NULL;
	size_t i = 0;

	node = *deck;
	while (node)
	{
		node->card = array[i++];
		node = node->next;
	}
}

/**
 * sort_deck - sorts a deck of cards using quick sort
 * @deck: pointer to the head of the doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	size_t size = 0;
	const card_t **array = NULL;

	/* check for null or single node deck */
	if (!deck || !*deck || !(*deck)->next)
		return;

	size = count_deck(deck); /* count the number of nodes in the deck */
	array = create_array(deck, size); /* create an array of pointers to cards */
	if (!array)
		return;

	qsort(array, size, sizeof(card_t *), compare_cards);

	update_deck(deck, array, size); /* update the deck with the sorted array */

	free(array); /* free the array */
}
