#include <stdio.h>
#include <string.h>

#include "print.h"

extern uint8_t g_first_hand;
extern uint8_t g_second_hand;

extern bool g_stand[2];
extern bool g_dOuble[2];
extern bool g_split;

bool    hitable(player_s* player, uint8_t idx) {
    if (!g_stand[idx] && !g_dOuble[idx] && player->nb_cards[idx] >= MIN_HAND_CARDS && player->points[idx] <= BLACKJACK) {
        return true;
    }
    return false;
}

bool    standalbe(player_s* player, uint8_t idx) {
    if (!g_stand[idx] && !g_dOuble[idx] && player->nb_cards[idx] >= MIN_HAND_CARDS && player->points[idx] <= BLACKJACK) {
        return true;
    }
    return false;
}

bool    dOubleable(player_s* player, uint8_t idx) {
    if (!g_stand[idx] && !g_dOuble[idx] && player->nb_cards[idx] >= MIN_HAND_CARDS && player->points[idx] <= BLACKJACK) {
        return true;
    }
    return false;
}

bool    splitable(player_s* player) {
    if (player->nb_cards[FIRST_HAND] == 2 && player->nb_cards[SECOND_HAND] == 0 && player->hand[FIRST_HAND][FIRST_CARD].value == player->hand[FIRST_HAND][SECOND_CARD].value) {
        return true;
    }
    return false;
}

void    hit(deck_s* deck, player_s* player, uint8_t idx) {
    if (hitable(player, idx)) {
        pick_card(deck, player, &idx);
    } else {
        hit_error();
    }
}

void    stand(player_s* player, uint8_t idx) {
    if (standalbe(player, idx)) {
        g_stand[idx] = true;
    } else {
        stand_error();
    }
}

void    dOuble(deck_s* deck, player_s* player, uint8_t idx) {
    if (dOubleable(player, idx)) {
        player->balance -= player->bet[idx];
        player->bet[idx] *= 2;
        pick_card(deck, player, &idx);
        g_dOuble[idx] = true;
    } else {
        dOuble_error();
    }
}

void    split(deck_s* deck, player_s* player) {
    if (splitable(player)) {
        player->balance -= player->bet[FIRST_HAND];
        player->bet[SECOND_HAND] = player->bet[FIRST_HAND];
        memcpy(&(player->hand[SECOND_HAND][FIRST_CARD]), &(player->hand[FIRST_HAND][SECOND_CARD]), sizeof(card_s));
        player->nb_cards[FIRST_HAND] = 1;
        player->nb_cards[SECOND_HAND] = 1;
        pick_card(deck, player, &g_first_hand);
        pick_card(deck, player, &g_second_hand);
        g_split = true;
    } else {
        split_error();
    }
}
