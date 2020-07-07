#include <stdbool.h>

#include "person.h"
#include "action.h"

#define THRESHOLD   16

extern uint8_t first_hand;
extern uint8_t second_hand;

void    bet(player_s* player) {
    player->bet[FIRST_HAND] = 2;
}

void    player_turn(deck_s* deck, player_s* player) {
    while (player->points[FIRST_HAND] <= THRESHOLD) {
        pick_card(deck, player, &first_hand);
    }
    if (standalbe(player, first_hand)) {
        stand(player, first_hand);
    }
}
