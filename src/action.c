#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "person.h"
#include "game.h"
#include "print.h"
#include "deck.h"

static const uint8_t first_hand = 0;
static const uint8_t second_hand = 1;

/*
** Initializes a new Black Jack game turn
** by reseting player's hand and bet, reseting
** dealer's hand and getting a new deck.
*/
void    init_turn(deck_s* deck, player_s* player, dealer_s* dealer) {
    for (int i = 0; i < MAX_HAND; i++) {
        memset(player->hand[i], 0, sizeof(card_s) * MAX_HAND_CARDS);
    }
    memset(player->nb_cards, 0, sizeof(uint8_t) * MAX_HAND);
    memset(player->points, 0, sizeof(uint8_t) * MAX_HAND);
    player->splited = false;
    player->doubled = false;
    player->bet = 0;

    memset(dealer, 0, sizeof(dealer_s));

    get_deck(deck);
    // TO DELETE
    for (int i = 0; i < 15; i++) {
        printf("%d: %s of %s: %d\n", i, deck->cards[i].name, deck->cards[i].color, deck->cards[i].value);
    }
    printf("\n");
    // END
}

/*
** Distributes 2 cards to player and 2 cards
** to dealer one by one starting by player.
*/
void    distribute(deck_s* deck, player_s* player, dealer_s* dealer) {
    pick_card(deck, player, &first_hand);
    pick_card(deck, dealer, NULL);
    pick_card(deck, player, &first_hand);
    pick_card(deck, dealer, NULL);

    // TO DELETE
    printf("%s of %s: %d\n", player->hand[0][0].name, player->hand[0][0].color, player->hand[0][0].value);
    printf("%s of %s: %d\n", dealer->hand[0].name, dealer->hand[0].color, dealer->hand[0].value);
    printf("%s of %s: %d\n", player->hand[0][1].name, player->hand[0][1].color, player->hand[0][1].value);
    printf("%s of %s: %d\n", dealer->hand[1].name, dealer->hand[1].color, dealer->hand[1].value);
    printf("\n");
    // END


    #ifdef  SHOW_PRINT
    show_hands(player, dealer, true);
    #endif
}

// void    split(deck_s* deck, player_s* player) {
//     memcpy(&(player->hand[1][0]), &(player->hand[0][1]), sizeof(card_s) * MAX_HAND_CARDS);
//     memset(&(player->hand[0][1]), 0, sizeof(card_s) * MAX_HAND_CARDS);
//     player->splited = true;
// }

// void    double_bet(deck_s* deck, player_s* player) {
//     player->balance -= player->bet;
//     player->bet *= 2;
//     player_pick_card(deck, player, false);
//     player->doubled = true;
// }
