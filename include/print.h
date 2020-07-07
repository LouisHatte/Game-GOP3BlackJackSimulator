#pragma once

#include <stdbool.h>

#include "person.h"

// Comment these lines to hide prints
#define SHOW_PRINT
#define SHOW_ERROR

void    show_hands(player_s* player, dealer_s* dealer, bool hide_dealer_card);
void    show_balance(player_s* player);

void    blackjack_player(void);
void    blackjack_dealer(void);
void    burst_player(void);
void    burst_dealer(void);
void    player_win(void);
void    player_lose(void);
void    push(void);

void    error(player_s* player, dealer_s* dealer);
void    hit_error(void);
void    stand_error(void);
void    dOuble_error(void);
void    split_error(void);
