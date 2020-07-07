#pragma once

#include "deck.h"

#define FIRST_HAND  0
#define SECOND_HAND 1

#define FIRST_CARD  0
#define SECOND_CARD 1

typedef struct player {
    card_s      hand[MAX_HAND][MAX_HAND_CARDS];
    uint8_t     nb_cards[MAX_HAND];
    uint8_t     points[MAX_HAND];
    int64_t     balance;
    uint64_t    bet[MAX_HAND];
} player_s;

typedef struct dealer {
    card_s  hand[MAX_HAND_CARDS];
    uint8_t nb_cards;
    uint8_t points;
} dealer_s;

void    bet(player_s* player);
void    player_turn(deck_s* deck, player_s* player);
