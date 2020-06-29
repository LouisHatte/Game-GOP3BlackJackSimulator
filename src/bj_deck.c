#include <string.h>
#include <stdlib.h>

#include "deck.h"
#include "person.h"

extern deck_s DECK;

#include <stdio.h>

void    _shift_left_tab(uint8_t t[], uint8_t size, uint8_t idx) {
    for (int i = idx; i < size - 1; i++) {
        t[i] = t[i + 1];
    }
    t[size - 1] = 0;
}

void    _shift_left_deck(deck_s* deck, uint8_t size, uint8_t idx) {
    for (int i = idx; i < size - 1; i++) {
        memcpy(&(deck->cards[i]), &(deck->cards[i + 1]), sizeof(card_s));
    }
    memset(deck->cards[size - 1].name, 0, sizeof(char) * NAME_LENGTH);
    memset(deck->cards[size - 1].color, 0, sizeof(char) * COLOR_LENGTH);
    deck->cards[size - 1].value = 0;
}

void    shift_left_bj_deck(bj_deck_s* deck, uint8_t size, uint8_t idx) {
    for (int i = idx; i < size - 1; i++) {
        memcpy(&(deck->cards[i]), &(deck->cards[i + 1]), sizeof(card_s));
    }
    memset(deck->cards[size - 1].name, 0, sizeof(char) * NAME_LENGTH);
    memset(deck->cards[size - 1].color, 0, sizeof(char) * COLOR_LENGTH);
    deck->cards[size - 1].value = 0;
}

void    get_deck(bj_deck_s* deck) {
    uint8_t cards_left[NB_DECK_CARDS];
    deck_s* tmp_deck = malloc(sizeof(deck_s));
    uint8_t r = 0;
    uint8_t size = NB_DECK_CARDS;

    memset(cards_left, NB_BJ_DECK, sizeof(uint8_t) * NB_DECK_CARDS);
    memcpy(tmp_deck, &DECK, sizeof(deck_s));

    for (int i = 0; i < NB_BJ_CARDS; i++) {
        r = rand() % size;
        memcpy(&(deck->cards[i]), &(tmp_deck->cards[r]), sizeof(card_s));
        cards_left[r] -= 1;
        if (cards_left[r] == 0) {
            _shift_left_tab(cards_left, size, r);
            _shift_left_deck(tmp_deck, size, r);
            size -= 1;
        }
    }
    free(tmp_deck);
}
