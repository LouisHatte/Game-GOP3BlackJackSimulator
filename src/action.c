#include <string.h>
#include <stdbool.h>

#include "person.h"
#include "game.h"

void    init_game_turn(player_s* player, dealer_s* dealer) {
    for (int i = 0; i < MAX_HAND; i++) {
        memset(player->hand[i], 0, sizeof(card_s) * MAX_HAND_CARDS);
    }
    memset(player->nb_cards, 0, sizeof(uint8_t) * MAX_HAND);
    memset(player->points, 0, sizeof(uint8_t) * MAX_HAND);
    player->splited = false;
    player->bet = 0;

    memset(dealer, 0, sizeof(dealer_s));
}

uint8_t calculate_points(card_s hand[MAX_HAND_CARDS], uint8_t nb_cards) {
    uint8_t nb_ace = 0;
    uint8_t points = 0;

    for (int i = 0; i < nb_cards; i++) {
        points += hand[i].value;
        if (hand[i].value == ACE) {
            nb_ace++;
        }
    }
    for (int i = 0; i < nb_ace; i++) {
        if (points > BLACKJACK) {
            points -= BLACKJACK - ONE;
        }
    }
    return points;
}

void    player_pick_card(bj_deck_s* deck, player_s* player, bool second_hand) {
    uint8_t idx = (second_hand) ? 1 : 0;

    memcpy(&(player->hand[idx][player->nb_cards[idx]]), &(deck->cards[0]), sizeof(card_s));
    player->nb_cards[idx] += 1;
    player->points[idx] = calculate_points(player->hand[0], player->nb_cards[0]);
    shift_left_bj_deck(deck, NB_DECK_CARDS, 0);
}

void    dealer_pick_card(bj_deck_s* deck, dealer_s* dealer) {
    memcpy(&(dealer->hand[dealer->nb_cards]), &(deck->cards[0]), sizeof(card_s));
    dealer->nb_cards += 1;
    dealer->points = calculate_points(dealer->hand, dealer->nb_cards);
    shift_left_bj_deck(deck, NB_DECK_CARDS, 0);
}
