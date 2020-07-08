#include <stdio.h>
#include <stdlib.h>

#include "print.h"

extern uint8_t g_stand[2];
extern uint8_t g_dOuble[2];
extern uint8_t g_split;

/*
** Prints a card.
*/
static void _print_card(card_s card) {
    printf("    %s of %s: %d\n", card.name, card.color, card.value);
}

/*
** Prints Black Jack hand points.
*/
static void _print_points(uint8_t points) {
    if (points > BLACKJACK) {
        printf("Points: \033[31m%d\033[0m\n", points);
    } else {
        printf("Points: \033[32m%d\033[0m\n", points);
    }
}

/*
** Prints hands.
*/
void    show_hands(player_s* player, dealer_s* dealer, bool show_dealer_card) {
    #ifdef SHOW_PRINT
        printf("--------------------\nPlayer\n");
        for (int i = 0; i < MAX_HAND; i++) {
            for (int j = 0; j < player->nb_cards[i]; j++) {
                _print_card(player->hand[i][j]);
            }
            if (player->nb_cards[i] > 0) {
                _print_points(player->points[i]);
            }
        }

        printf("Dealer\n");
        if (show_dealer_card) {
            for (int i = 0; i < dealer->nb_cards; i++) {
                _print_card(dealer->hand[i]);
            }
            _print_points(dealer->points);
        } else {
            _print_card(dealer->hand[FIRST_CARD]);
            _print_points(dealer->hand[FIRST_CARD].value);
        }
        printf("\n");
    #endif
}

void    show_balance(player_s* player) {
    #ifdef  SHOW_PRINT
        printf("Balance: \033[33m%ld\033[0m\n", player->balance);
    #endif
}

void    blackjack_player(void) {
    #ifdef  SHOW_PRINT
        printf("BLACKJACK!!!\n");
    #endif
}

void    blackjack_dealer(void) {
    #ifdef  SHOW_PRINT
        printf("DEALER'S BLACKJACK :c\n");
    #endif
}

void    burst_player(void) {
    #ifdef  SHOW_PRINT
        printf("BURST...\n");
    #endif
}

void    burst_dealer(void) {
    #ifdef  SHOW_PRINT
        printf("DEALER BURST!\n");
    #endif
}

void    player_win(void) {
    #ifdef  SHOW_PRINT
        printf("PLAYER WIN :)\n");
    #endif
}

void    player_lose(void) {
    #ifdef  SHOW_PRINT
        printf("PLAYER LOSE :(\n");
    #endif
}

void    push(void) {
    #ifdef  SHOW_PRINT
        printf("PUSH.\n");
    #endif
}

void    error(player_s* player, dealer_s* dealer) {
    #ifdef  SHOW_ERROR
        dprintf(2, "\033[31mPlayer didn't end his turn.\033[0m\n");
        show_hands(player, dealer, true);
        dprintf(2, "\033[31m--------------------\n    Split: %s\n", g_split ? "true" : "false");
        dprintf(2, "First Hand\n");
        dprintf(2, "    Stand: %s\n", g_stand[FIRST_HAND] ? "true": "false");
        dprintf(2, "    Double: %s\033[0m\n", g_dOuble[FIRST_HAND] ? "true" : "false");
        if (g_split) {
            dprintf(2, "\033[31mSecond Hand\n");
            dprintf(2, "    Stand: %s\n", g_stand[SECOND_HAND] ? "true": "false");
            dprintf(2, "    Double: %s\033[0m\n", g_dOuble[SECOND_HAND] ? "true" : "false");
        }
    #endif
    exit(1);
}

void    hit_error(void) {
    #ifdef  SHOW_ERROR
        dprintf(2, "\033[31mYou can't hit\033[0m\n");
    #endif
    exit(1);
}

void    stand_error(void) {
    #ifdef  SHOW_ERROR
        dprintf(2, "\033[31mYou can't stand\033[0m\n");
    #endif
    exit(1);
}

void    dOuble_error(void) {
    #ifdef  SHOW_ERROR
        dprintf(2, "\033[31mYou can't double\033[0m\n");
    #endif
    exit(1);
}

void    split_error(void) {
    #ifdef  SHOW_ERROR
        dprintf(2, "\033[31mYou can't split\033[0m\n");
    #endif
    exit(1);
}
