#pragma once

#include <stdbool.h>

#include "person.h"

bool    hitable(player_s* player, uint8_t idx);
bool    standalbe(player_s* player, uint8_t idx);
bool    dOubleable(player_s* player, uint8_t idx);
bool    splitable(player_s* player);

void    hit(deck_s* deck, player_s* player, uint8_t idx, dealer_s* dealer);
void    stand(player_s* player, uint8_t idx, dealer_s* dealer);
void    dOuble(deck_s* deck, player_s* player, uint8_t idx, dealer_s* dealer);
void    split(deck_s* deck, player_s* player, dealer_s* dealer);
