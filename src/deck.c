#include <string.h>
#include <stdlib.h>

#include "person.h"

extern card_s G_CARDS[52];

static void _shift_left_tab(uint8_t t[], uint8_t size, uint8_t idx) {
    for (int i = idx; i < size - 1; i++) {
        t[i] = t[i + 1];
    }
    t[size - 1] = 0;
}

static void _shift_left_deck(card_s cards[], uint8_t size, uint8_t idx) {
    for (int i = idx; i < size - 1; i++) {
        memcpy(&(cards[i]), &(cards[i + 1]), sizeof(card_s));
    }
    memset(cards[size - 1].name, 0, sizeof(char) * NAME_LENGTH);
    memset(cards[size - 1].color, 0, sizeof(char) * COLOR_LENGTH);
    cards[size - 1].value = 0;
}

/*
** Gets a new deck of 312 cards.
*/
void    get_deck(deck_s* deck) {
    card_s cards[NB_DECK_CARDS];
    uint8_t cards_left[NB_DECK_CARDS];
    uint8_t r = 0;
    uint8_t size = NB_DECK_CARDS;

    memset(cards_left, NB_DECK_S, sizeof(uint8_t) * NB_DECK_CARDS);
    memcpy(cards, &G_CARDS, sizeof(card_s) * NB_DECK_CARDS);

    for (int i = 0; i < NB_BJ_CARDS; i++) {
        r = rand() % size;
        memcpy(&(deck->cards[i]), &(cards[r]), sizeof(card_s));
        cards_left[r] -= 1;
        if (cards_left[r] == 0) {
            _shift_left_tab(cards_left, size, r);
            _shift_left_deck(cards, size, r);
            size -= 1;
        }
    }
}

/*
** Counts Black Jack points.
*/
static uint8_t  _get_points(card_s hand[MAX_HAND_CARDS], uint8_t nb_cards) {
    uint8_t nb_ace = 0;
    uint8_t points = 0;

    for (int i = 0; i < nb_cards; i++) {
        points += hand[i].value;
        if (hand[i].value == ACE) {
            nb_ace++;
        }
    }
    for (int i = 0; i < nb_ace; i++) {
        if (points > BLACKJACK) {
            points -= 10;
        }
    }
    return points;
}

/*
** Picks a card from the deck and add it to
** a hand then calculate new Black Jack points.
*/
void    pick_card(deck_s* deck, void* person, const uint8_t* idx) {
    if (!idx) {
        memcpy(&(((dealer_s*) person)->hand[((dealer_s*) person)->nb_cards]), &(deck->cards[0]), sizeof(card_s));
        _shift_left_deck(deck->cards, NB_DECK_CARDS, 0);
        ((dealer_s*) person)->nb_cards += 1;
        ((dealer_s*) person)->points = _get_points(((dealer_s*) person)->hand, ((dealer_s*) person)->nb_cards);
    } else {
        memcpy(&(((player_s*) person)->hand[*idx][((player_s*) person)->nb_cards[*idx]]), &(deck->cards[0]), sizeof(card_s));
        _shift_left_deck(deck->cards, NB_DECK_CARDS, 0);
        ((player_s*) person)->nb_cards[*idx] += 1;
        ((player_s*) person)->points[*idx] = _get_points(((player_s*) person)->hand[*idx], ((player_s*) person)->nb_cards[*idx]);
    }
}
