/**
 * struct card_s - Represents a card in a deck
 *
 * @value: Value of the card (Ace=1, 2-10, Jack=11, Queen=12, King=13)
 * @kind: Suit of the card (Spade, Heart, Diamond, Club)
 */
typedef struct card_s
{
        int value;
        char *kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a deck of cards
 *
 * @card: Pointer to the card contained in the node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
	card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
