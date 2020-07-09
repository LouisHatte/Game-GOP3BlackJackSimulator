#include "player.h"
#include "action.h"
#include "tabler.h"
#include "bet.h"

#include <stdio.h>
#include <stdlib.h>

extern uint8_t g_first_hand;
extern uint8_t g_second_hand;

extern tabler_s g_tabler;

extern int64_t g_bet[NB_BET];

void    bet(player_s* player, uint8_t idx) {
    if (player->lose_strick >= NB_BET) {
        player->lose_strick = 0;
    }
    player->bet[idx] = g_bet[player->lose_strick];
}

static bool _is_soft_totals(player_s* player, uint8_t idx) {
    for (int i = 0; i < player->nb_cards[idx]; i++) {
        if (player->hand[idx][i].value == ACE) {
            return true;
        }
    }
    return false;
}

static uint8_t  _get_soft_value(card_s hand[MAX_HAND_CARDS], uint8_t nb_cards) {
    uint8_t points = 0;

    for (int i = 0; i < nb_cards; i++) {
        if (hand[i].value == ACE) {
            points += 1;
        } else {
            points += hand[i].value;
        }
    }
    if (points > 10) {
        points %= ACE;
    } else {
        points -= 1;
    }
    return points;
}

static void _play_hand(deck_s* deck, player_s* player, dealer_s* dealer, uint8_t idx) {
    uint8_t soft_points = 0;

    while (1) {
        if (_is_soft_totals(player, idx)) {
            soft_points = _get_soft_value(player->hand[idx], player->nb_cards[idx]);
            if (player->points[idx] > BLACKJACK) {
                break;
            } else if (player->points[idx] == BLACKJACK) {
                // printf("STAND SOFT\n");
                stand(player, idx, dealer);
                break;
            } else if (g_tabler.soft[soft_points][dealer->hand[FIRST_CARD].value] == STAND) {
                // printf("STAND SOFT\n");
                stand(player, idx, dealer);
                break;
            } else if (g_tabler.soft[soft_points][dealer->hand[FIRST_CARD].value] == HIT) {
                // printf("HIT SOFT\n");
                hit(deck, player, idx, dealer);
            } else if (g_tabler.soft[soft_points][dealer->hand[FIRST_CARD].value] == DOUBLE) {
                // printf("DOUBLE SOFT\n");
                dOuble(deck, player, idx, dealer);
                break;
            }
        } else {
            if (player->points[idx] > BLACKJACK) {
                break;
            } else if (player->points[idx] == BLACKJACK) {
                // printf("STAND HARD\n");
                stand(player, idx, dealer);
                break;
            } else if (g_tabler.hard[player->points[idx]][dealer->hand[FIRST_CARD].value] == STAND) {
                // printf("STAND HARD\n");
                stand(player, idx, dealer);
                break;
            } else if (g_tabler.hard[player->points[idx]][dealer->hand[FIRST_CARD].value] == HIT) {
                // printf("HIT HARD\n");
                hit(deck, player, idx, dealer);
            } else if (g_tabler.hard[player->points[idx]][dealer->hand[FIRST_CARD].value] == DOUBLE) {
                // printf("DOUBLE HARD\n");
                dOuble(deck, player, idx, dealer);
                break;
            }
        }
    }
}

void    player_turn(deck_s* deck, player_s* player, dealer_s* dealer) {
    if (splitable(player)) {
        if (g_tabler.split[player->hand[FIRST_HAND][FIRST_CARD].value][dealer->hand[FIRST_CARD].value] == SPLIT) {
            split(deck, player, dealer);
        }
    }
    // printf("------FIRST HAND------\n");
    _play_hand(deck, player, dealer, g_first_hand);
    // printf("----------------------\n");
    if (player->nb_cards[SECOND_HAND] == 2) {
        // printf("------SECOND HAND------\n")
        _play_hand(deck, player, dealer, g_second_hand);
        // printf("----------------------\n");
    }
}
