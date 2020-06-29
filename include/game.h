#pragma once

#include "person.h"

#define BLACKJACK   21
#define ACE         11
#define ONE         1

void    game_loop(bj_deck_s* deck, player_s* player, dealer_s* dealer);