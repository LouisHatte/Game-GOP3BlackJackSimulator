#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "person.h"
#include "game.h"
#include "print.h"
#include "deck.h"
#include "game.h"

const uint8_t first_hand = 0;
const uint8_t second_hand = 1;

extern card_s CARDS[52];

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
    // player->splited = false;
    // player->doubled = false;
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
    // pick_card(deck, player, &first_hand);
    // pick_card(deck, dealer, NULL);
    // pick_card(deck, player, &first_hand);
    // pick_card(deck, dealer, NULL);

    // TO DELETE

    // P BJ D 20
    // memcpy(&(player->hand[0][0]), &(CARDS[0]), sizeof(card_s));
    // memcpy(&(player->hand[0][1]), &(CARDS[10]), sizeof(card_s));
    // player->nb_cards[0] = 2;
    // player->points[0] = CARDS[0].value + CARDS[10].value;
    // memcpy(&(dealer->hand[0]), &(CARDS[11]), sizeof(card_s));
    // memcpy(&(dealer->hand[1]), &(CARDS[12]), sizeof(card_s));
    // dealer->nb_cards = 2;
    // dealer->points = CARDS[11].value + CARDS[12].value;

    // P 20 D BJ
    // memcpy(&(player->hand[0][0]), &(CARDS[11]), sizeof(card_s));
    // memcpy(&(player->hand[0][1]), &(CARDS[12]), sizeof(card_s));
    // player->nb_cards[0] = 2;
    // player->points[0] = CARDS[11].value + CARDS[12].value;
    // memcpy(&(dealer->hand[0]), &(CARDS[0]), sizeof(card_s));
    // memcpy(&(dealer->hand[1]), &(CARDS[10]), sizeof(card_s));
    // dealer->nb_cards = 2;
    // dealer->points = CARDS[0].value + CARDS[10].value;

    // P 20 D 20
    // memcpy(&(player->hand[0][0]), &(CARDS[11]), sizeof(card_s));
    // memcpy(&(player->hand[0][1]), &(CARDS[12]), sizeof(card_s));
    // player->nb_cards[0] = 2;
    // player->points[0] = CARDS[11].value + CARDS[12].value;
    // memcpy(&(dealer->hand[0]), &(CARDS[11]), sizeof(card_s));
    // memcpy(&(dealer->hand[1]), &(CARDS[10]), sizeof(card_s));
    // dealer->nb_cards = 2;
    // dealer->points = CARDS[11].value + CARDS[10].value;

    // P 15 D 20
    // memcpy(&(player->hand[0][0]), &(CARDS[11]), sizeof(card_s));
    // memcpy(&(player->hand[0][1]), &(CARDS[4]), sizeof(card_s));
    // player->nb_cards[0] = 2;
    // player->points[0] = CARDS[11].value + CARDS[4].value;
    // memcpy(&(dealer->hand[0]), &(CARDS[11]), sizeof(card_s));
    // memcpy(&(dealer->hand[1]), &(CARDS[10]), sizeof(card_s));
    // dealer->nb_cards = 2;
    // dealer->points = CARDS[11].value + CARDS[10].value;

    // P 20 D 15
    memcpy(&(player->hand[0][0]), &(CARDS[11]), sizeof(card_s));
    memcpy(&(player->hand[0][1]), &(CARDS[12]), sizeof(card_s));
    player->nb_cards[0] = 2;
    player->points[0] = CARDS[11].value + CARDS[12].value;
    memcpy(&(dealer->hand[0]), &(CARDS[11]), sizeof(card_s));
    memcpy(&(dealer->hand[1]), &(CARDS[4]), sizeof(card_s));
    dealer->nb_cards = 2;
    dealer->points = CARDS[11].value + CARDS[4].value;


    // END

    show_hands(player, dealer, false);
}

void    announce_results(player_s* player, dealer_s* dealer) {
    show_hands(player, dealer, true);

    if (player->hand[0][0].value + player->hand[0][1].value == BLACKJACK) {
        player->balance += player->bet * 2.5;
        blackjack_player();
    } else if (player->points[0] > BLACKJACK) {
        burst_player();
    } else if (dealer->hand[0].value + dealer->hand[1].value == BLACKJACK) {
        blackjack_dealer();
    } else if (dealer->points > BLACKJACK) {
        player->balance += player->bet * 2;
        burst_dealer();
    } else if (player->points[0] == dealer->points) {
        player->balance += player->bet;
        push();
    } else if (player->points[0] > dealer->points) {
        player->balance += player->bet * 2;
        player_win();
    } else {
        player_lose();
    }

    printf("Balance: %ld\n", player->balance);
}
