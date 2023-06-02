#include "deck.h"


/**
 * sort_deck - Sorts a deck of cards in ascending order by value and suit
 *
 * @deck: Double pointer to the head node of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int num_cards = 0, i = 0;
	deck_node_t *current, *tmp;
	card_t **cards;

	if (deck == NULL || *deck == NULL)
		return;

	/* Count number of cards in deck */
	current = *deck;
	while (current != NULL)
	{
		num_cards++;
		current = current->next;
	}

	/* Allocate array of card pointers */
	cards = malloc(num_cards * sizeof(card_t *));
	if (cards == NULL)
		return;

	/* Copy card pointers to array */
	current = *deck;
	while (current != NULL)
	{
		cards[i++] = current->card;
		current = current->next;
	}

	/* Sort the array using qsort */
	qsort(cards, num_cards, sizeof(card_t *), compare_cards);

	current = *deck;
	for (i = 0; i < num_cards; i++)
	{
		current->card = cards[i];
		tmp = current->next;
		if (tmp != NULL)
			tmp->prev = current;
		current = tmp;
	} free(cards);
}

/**
 * compare_cards - Compares two card pointers for sorting
 *
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: -1 if a < b, 0 if a == b, 1 if a > b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = *(const card_t **)a;
	const card_t *card_b = *(const card_t **)b;
	int result;

	/* Sort by value */
	result = card_a->value - card_b->value;
	if (result != 0)
		return (result);

	/* If values are equal, sort by suit */
	return (strcmp(card_a->kind, card_b->kind));
}
