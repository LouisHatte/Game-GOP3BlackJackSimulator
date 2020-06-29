#pragma once

#include <stdint.h>

#define NAME_LENGTH     6
#define COLOR_LENGTH    8

#define NB_DECK_CARDS   52
#define NB_BJ_DECK      6
#define NB_BJ_CARDS     (NB_DECK_CARDS * NB_BJ_DECK)

#define MAX_HAND        2
#define MAX_HAND_CARDS  11

typedef struct card {
    char    name[NAME_LENGTH];
    char    color[COLOR_LENGTH];
    uint8_t value;
} card_s;

typedef struct deck {
    card_s  cards[NB_DECK_CARDS];
} deck_s;

typedef struct bj_deck {
    card_s  cards[NB_BJ_CARDS];
} bj_deck_s;

void    get_deck(bj_deck_s* deck);
void    shift_left_bj_deck(bj_deck_s* deck, uint8_t size, uint8_t idx);
