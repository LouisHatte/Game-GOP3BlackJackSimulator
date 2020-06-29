#pragma once

#include <stdbool.h>

#include "deck.h"

typedef struct player {
    card_s      hand[MAX_HAND][MAX_HAND_CARDS];
    uint8_t     nb_cards[MAX_HAND];
    uint8_t     points[MAX_HAND];
    bool        splited;
    int64_t     balance;
    uint64_t    bet;
} player_s;

typedef struct dealer {
    card_s  hand[MAX_HAND_CARDS];
    uint8_t nb_cards;
    uint8_t points;
} dealer_s;

void    bet(player_s* player);
bool    player_turn(bj_deck_s* deck, player_s* player);
void    dealer_turn(bj_deck_s* deck, dealer_s* dealer);