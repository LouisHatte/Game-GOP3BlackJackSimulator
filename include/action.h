#pragma once

#include <stdbool.h>

void    init_turn(deck_s* deck, player_s* player, dealer_s* dealer);
void    distribute(deck_s* deck, player_s* player, dealer_s* dealer);
void    player_pick_card(deck_s* deck, player_s* player, bool second_hand);
void    dealer_pick_card(deck_s* deck, dealer_s* dealer);
void    double_bet(deck_s* deck, player_s* player);
