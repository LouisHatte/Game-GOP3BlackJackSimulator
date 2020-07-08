#pragma once

#include <stdbool.h>

#include "person.h"

#define NB_GAME 10000

#define DEALER_THRESHOLD    16

void    init_turn(deck_s* deck, player_s* player, dealer_s* dealer);
void    distribute(deck_s* deck, player_s* player, dealer_s* dealer);
void    play_turn(deck_s* deck, player_s* player, dealer_s* dealer);
void    announce_results(player_s* player, dealer_s* dealer, uint8_t idx);
