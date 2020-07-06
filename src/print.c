#include "person.h"
#include "print.h"
#include "game.h"

#include <stdio.h>

void    _print_card(card_s card) {
    printf("    %s of %s: %d\n", card.name, card.color, card.value);
}

void    _print_points(uint8_t points) {
    if (points > BLACKJACK) {
        printf("Points: \033[31m%d\033[0m\n", points);
    } else {
        printf("Points: \033[32m%d\033[0m\n", points);
    }
}

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
        } else {
            _print_card(dealer->hand[0]);
        }
        _print_points(dealer->points);
        printf("\n");
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
