#include <stdio.h>

#include "person.h"
#include "action.h"
#include "game.h"
#include "print.h"

void    get_results(player_s* player, dealer_s* dealer) {
    if (player->hand[0][0].value + player->hand[0][1].value == BLACKJACK) {
        player->balance += player->bet * 2.5;
        printf("BLACKJACK!!!\n");
    } else if (player->points[0] > BLACKJACK) {
        printf("BURST...\n");
    } else if (dealer->hand[0].value + dealer->hand[1].value == BLACKJACK) {
        printf("DEALER'S BLACKJACK :c\n");
    } else if (dealer->points > BLACKJACK) {
        player->balance += player->bet * 2;
        printf("DEALER BURST!\n");
    } else if (player->points[0] == dealer->points) {
        player->balance += player->bet;
        printf("PUSH.\n");
    } else if (player->points[0] > dealer->points) {
        player->balance += player->bet * 2;
        printf("YOU WIN :)\n");
    } else {
        printf("YOU LOSE :(\n");
    }
}

void    game_loop(deck_s* deck, player_s* player, dealer_s* dealer) {
    bool    play_again = false;

    if (player->points[0] != BLACKJACK) {
        while (1) {
            play_again = player_turn(deck, player);
            show_hands(player, dealer, true);
            if (player->points[0] > BLACKJACK || !play_again || player->doubled) {
                break;
            }
        }
        if (player->points[0] <= BLACKJACK) {
            dealer_turn(deck, dealer);
            show_hands(player, dealer, false);
        }
    }

    get_results(player, dealer);
}
