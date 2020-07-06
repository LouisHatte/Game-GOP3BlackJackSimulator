#pragma once

#include "person.h"

#define NB_GAME     100

#define BLACKJACK   21
#define ACE         11
#define ONE         1

void    distribute(deck_s* deck, player_s* player, dealer_s* dealer);
void    game_loop(deck_s* deck, player_s* player, dealer_s* dealer);
void    show_hands(player_s* player, dealer_s* dealer, bool hide_dealer_card);
void    announce_results(player_s* player, dealer_s* dealer);
