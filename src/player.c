#include <stdbool.h>

#include "person.h"
#include "action.h"

#define THRESHOLD   16

void    bet(player_s* player) {
    player->bet = 500000;
}

bool    player_turn(deck_s* deck, player_s* player) {
    if (player->points[0] <= THRESHOLD) {
        // double_bet()
        // player_pick_card(deck, player, false);
        return true;
    }
    return false;
}
