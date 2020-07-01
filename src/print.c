#include "person.h"

#include <stdio.h>

void    show_hands(player_s* player, dealer_s* dealer, bool hide_dealer_card) {
    uint8_t player_nb_cards = player->nb_cards[0] + player->nb_cards[1];
    uint8_t highest = (dealer->nb_cards >= player_nb_cards) ? dealer->nb_cards : player_nb_cards;
    bool flag = false;
    uint8_t j = 0;

    printf("%d\n", player->nb_cards[0]);
    printf("You:\t\t\tDealer:\n");
    for (int i = 0; i < highest; i++) {

        if (i < player->nb_cards[0] && !flag) {
            // printf("A\n");
            printf("%s of %s: %d\t", player->hand[0][i].name, player->hand[0][i].color, player->hand[0][i].value);
        }

        if (i >= player->nb_cards[0] && !flag) {
            // printf("B\n");
            printf("\n");
            flag = true;
        }

        if (j < player->nb_cards[1] && flag) {
            // printf("C\n");
            printf("%s of %s: %d\t", player->hand[1][j].name, player->hand[0][j].color, player->hand[0][j].value);
            j++;
        }

        if ((i < dealer->nb_cards && !flag && i >= player->nb_cards[0]) || (i < dealer->nb_cards && flag && j >= player->nb_cards[1])) {
            // printf("D\n");
            printf("\t\t\t");
        }

        if (i < dealer->nb_cards) {
            // printf("E\n");
            if (i == 1 && hide_dealer_card) {
                printf("???\n");
            } else {
                printf("%s of %s:\t%d\n", dealer->hand[i].name, dealer->hand[i].color, dealer->hand[i].value);
            }
        }
    }

    if (highest != dealer->nb_cards) {
        printf("\n");
    }

    if (hide_dealer_card) {
        printf("Total:\n%d\t\t\t%d\n\n", player->points[0], dealer->hand[0].value);
    } else {
        printf("Total:\n%d\t\t\t%d\n\n", player->points[0], dealer->points);
    }
}