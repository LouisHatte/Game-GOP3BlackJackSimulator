#include <string.h>
#include <stdbool.h>

#include "person.h"

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

void    player_pick_card(bj_deck_s* deck, player_s* player, bool second_hand) {
    uint8_t idx = (second_hand) ? 1 : 0;

    memcpy(&(player->hand[idx][player->nb_cards[idx]]), &(deck->cards[0]), sizeof(card_s));
    player->points[idx] += deck->cards[0].value;
    player->nb_cards[idx] += 1;
    shift_left_bj_deck(deck, NB_DECK_CARDS, 0);
}

void    dealer_pick_card(bj_deck_s* deck, dealer_s* dealer) {
    memcpy(&(dealer->hand[dealer->nb_cards]), &(deck->cards[0]), sizeof(card_s));
    dealer->points += deck->cards[0].value;
    dealer->nb_cards += 1;
    shift_left_bj_deck(deck, NB_DECK_CARDS, 0);
}
