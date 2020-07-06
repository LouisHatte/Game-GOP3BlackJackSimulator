#pragma once

#include "person.h"

#define SHOW_PRINT  1

void    show_hands(player_s* player, dealer_s* dealer, bool hide_dealer_card);

void    blackjack_player(void);
void    blackjack_dealer(void);
void    burst_player(void);
void    burst_dealer(void);
void    player_win(void);
void    player_lose(void);
void    push(void);
