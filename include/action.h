#pragma once

#include <stdbool.h>

void    init_game_turn(player_s* player, dealer_s* dealer);
void    player_pick_card(bj_deck_s* deck, player_s* player, bool second_hand);
void    dealer_pick_card(bj_deck_s* deck, dealer_s* dealer);