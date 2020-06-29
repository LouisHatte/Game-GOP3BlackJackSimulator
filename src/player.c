#include <stdbool.h>

#include "person.h"
#include "action.h"

#define THRESHOLD   16

void    bet(player_s* player) {
    player->bet = 1;
    player->balance -= player->bet;
}

bool    player_turn(bj_deck_s* deck, player_s* player) {
    if (player->points[0] <= THRESHOLD) {
        player_pick_card(deck, player, false);
        return true;
    }
    return false;
}
