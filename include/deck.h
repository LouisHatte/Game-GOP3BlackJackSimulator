#pragma once

#include <stdint.h>

#define BLACKJACK   21
#define ACE         11

#define NAME_LENGTH     6
#define COLOR_LENGTH    8

#define NB_DECK_CARDS   52
#define NB_DECK_S       6
#define NB_BJ_CARDS     (NB_DECK_CARDS * NB_DECK_S)

#define MAX_HAND        2
#define MAX_HAND_CARDS  22
#define MIN_HAND_CARDS  2

typedef struct card {
    char    name[NAME_LENGTH];
    char    color[COLOR_LENGTH];
    uint8_t value;
} card_s;

typedef struct deck {
    card_s cards[NB_BJ_CARDS];
} deck_s;

void    get_deck(deck_s* deck);
void    pick_card(deck_s* deck, void* person, const uint8_t* idx);
