#include "player.h"

extern uint8_t g_first_hand;
extern uint8_t g_second_hand;

void    bet(player_s* player) {
    player->bet[FIRST_HAND] = 2;
}

void    player_turn(deck_s* deck, player_s* player) {
    while (player->points[FIRST_HAND] <= THRESHOLD) {
        pick_card(deck, player, &g_first_hand);
    }
    if (standalbe(player, g_first_hand)) {
        stand(player, g_first_hand);
    }
}
