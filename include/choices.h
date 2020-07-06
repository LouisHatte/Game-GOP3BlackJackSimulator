#pragma once

#include "person.h"

void    hit(deck_s* deck, player_s* player, uint8_t idx);
void    stand(void);
void    dOuble(deck_s* deck, player_s* player, uint8_t idx);
void    split(void);
