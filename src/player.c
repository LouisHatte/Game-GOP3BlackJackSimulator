#include <stdbool.h>

#include "person.h"
#include "action.h"
#include "choices.h"

#define THRESHOLD   16

extern uint8_t first_hand;
extern uint8_t second_hand;

void    bet(player_s* player) {
    player->bet = 2;
}

void    player_turn(deck_s* deck, player_s* player) {
    if (player->points[0] <= THRESHOLD) {
        pick_card(deck, player, &first_hand);
    } else {
        stand();
    }
}
