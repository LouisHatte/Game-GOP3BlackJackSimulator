#include "person.h"
#include "game.h"

#include <stdio.h>

static bool v_hit = false;
static bool v_stand = false;
static bool v_dOuble = false;
static bool v_split = false;

void    play_turn(deck_s* deck, player_s* player, dealer_s* dealer) {
    if (player->points[FIRST_HAND] == BLACKJACK) {
        return;
    }

    while (1) {
        player_turn(deck, player);

        if (v_stand || player->points[FIRST_HAND] > BLACKJACK) {
            v_stand = false;
            break;
        }
    }

    if (dealer->points == BLACKJACK) {
        return;
    }

    if (player->points[0] <= BLACKJACK) {
        dealer_turn(deck, dealer);
    }
}

void    hit(deck_s* deck, player_s* player, uint8_t idx) {
    pick_card(deck, player, &idx);
    v_hit = true;
}

void    stand(void) {
    v_stand = true;
}

void    dOuble(deck_s* deck, player_s* player, uint8_t idx) {
    player->balance -= player->bet;
    player->bet *= 2;
    pick_card(deck, player, &idx);
    v_dOuble = true;
}

void    split(void) {

}