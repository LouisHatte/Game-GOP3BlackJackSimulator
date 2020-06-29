#include <stdio.h>

#include "person.h"
#include "action.h"
#include "game.h"

void    show_hands(player_s* player, dealer_s* dealer, bool hide_dealer_card) {
    uint8_t highest;

    if (dealer->nb_cards >= player->nb_cards[0] + player->nb_cards[1]) {
        highest = dealer->nb_cards;
    } else {
        highest = player->nb_cards[0] + player->nb_cards[1];
    }

    printf("You:\t\t\tDealer:\n");
    for (int i = 0; i < highest; i++) {
        if (i < player->nb_cards[0]) {
            printf("%s of %s: %d\t", player->hand[0][i].name, player->hand[0][i].color, player->hand[0][i].value);
        }
        if (i < dealer->nb_cards && i < player->nb_cards[0]) {
            if (i == 1 && hide_dealer_card) {
                printf("???\n");
            } else {
                printf("%s of %s: %d\n", dealer->hand[i].name, dealer->hand[i].color, dealer->hand[i].value);
            }
        } else if (i < dealer->nb_cards) {
            if (i == 1 && hide_dealer_card) {
                printf("\t\t\t???\n");
            } else {
                printf("\t\t\t%s of %s:\t%d\n", dealer->hand[i].name, dealer->hand[i].color, dealer->hand[i].value);
            }
        }
    }
    if (highest != dealer->nb_cards) {
        printf("\n");
    }
    if (hide_dealer_card) {
        printf("Points:\n%d\t\t\t%d\n\n", player->points[0], dealer->hand[0].value);
    } else {
        printf("Points:\n%d\t\t\t%d\n\n", player->points[0], dealer->points);
    }
}

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

void    game_loop(bj_deck_s* deck, player_s* player, dealer_s* dealer) {
    bool    play_again = false;

    init_game_turn(player, dealer);
    bet(player);

    player_pick_card(deck, player, false);
    dealer_pick_card(deck, dealer);
    player_pick_card(deck, player, false);
    dealer_pick_card(deck, dealer);
    show_hands(player, dealer, true);

    if (player->points[0] != BLACKJACK) {
        while (1) {
            play_again = player_turn(deck, player);
            show_hands(player, dealer, true);
            if (player->points[0] > BLACKJACK || !play_again) {
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
