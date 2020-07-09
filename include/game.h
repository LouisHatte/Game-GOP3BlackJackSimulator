#pragma once

#include <stdbool.h>

#include "person.h"

#define NB_GAME 10000

#define DEALER_THRESHOLD    16

#define BET_1   1000
#define BET_2   5000
#define BET_3   10000
#define BET_4   25000
#define BET_5   50000
#define BET_6   100000
#define BET_7   250000
#define BET_8   500000
#define BET_9   2500000
#define BET_10  10000000
#define BET_11  50000000

void    init_turn(deck_s* deck, player_s* player, dealer_s* dealer);
void    distribute(deck_s* deck, player_s* player, dealer_s* dealer);
void    play_turn(deck_s* deck, player_s* player, dealer_s* dealer);
void    announce_results(player_s* player, dealer_s* dealer, uint8_t idx);
