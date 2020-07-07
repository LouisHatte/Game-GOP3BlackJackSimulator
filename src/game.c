#include <string.h>

#include "print.h"
#include "game.h"

extern card_s CARDS[52];

extern uint8_t g_first_hand;
extern uint8_t g_second_hand;

extern bool g_stand[2];
extern bool g_dOuble[2];
extern bool g_split;


#include <unistd.h>

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
    player->bet[FIRST_HAND] = 0;
    player->bet[SECOND_HAND] = 0;

    memset(dealer, 0, sizeof(dealer_s));

    get_deck(deck);
}

/*
** Distributes 2 cards to player and 2 cards
** to dealer one by one starting by player.
*/
void    distribute(deck_s* deck, player_s* player, dealer_s* dealer) {
    pick_card(deck, player, &g_first_hand);
    pick_card(deck, dealer, NULL);
    pick_card(deck, player, &g_first_hand);
    pick_card(deck, dealer, NULL);

    show_hands(player, dealer, false);
}

/*
** Plays Black Jack turn.
*/
void    play_turn(deck_s* deck, player_s* player, dealer_s* dealer) {
    if (player->points[FIRST_HAND] == BLACKJACK) {
        return;
    }

    while (1) {
        player_turn(deck, player);

        if (!g_split) {
            if (player->points[FIRST_HAND] > BLACKJACK) {
                show_hands(player, dealer, false);
                return;
            }
            if (g_stand[FIRST_HAND] || g_dOuble[FIRST_HAND]) {
                break;
            }
        } else {
            if (player->points[FIRST_HAND] > BLACKJACK && player->points[SECOND_HAND] > BLACKJACK) {
                show_hands(player, dealer, false);
                return;
            }
            if (player->points[FIRST_HAND] > BLACKJACK && (g_stand[SECOND_HAND] || g_dOuble[SECOND_HAND])) {
                break;
            }
            if (player->points[SECOND_HAND] > BLACKJACK && (g_stand[FIRST_HAND] || g_dOuble[FIRST_HAND])) {
                break;
            }
            if ((g_stand[FIRST_HAND] || g_dOuble[FIRST_HAND]) && (g_stand[SECOND_HAND] || g_dOuble[SECOND_HAND])) {
                break;
            }
        }
        error(player, dealer);
        sleep(1);
    }
    show_hands(player, dealer, true);

    if (dealer->points == BLACKJACK) {
        return;
    }

    while (dealer->points <= DEALER_THRESHOLD) {
        pick_card(deck, dealer, NULL);
    }
    show_hands(player, dealer, true);
}

/*
** Resets Blackjack actions.
*/
static void _reset_actions(void) {
    g_stand[FIRST_HAND] = false;
    g_stand[SECOND_HAND] = false;
    g_dOuble[FIRST_HAND] = false;
    g_dOuble[SECOND_HAND] = false;
}

/*
** Announces Blackjack hand result.
*/
void    announce_results(player_s* player, dealer_s* dealer, uint8_t idx) {
    if (player->nb_cards[FIRST_HAND] == 2 && player->nb_cards[SECOND_HAND] == 0 && player->hand[FIRST_HAND][FIRST_CARD].value + player->hand[FIRST_HAND][SECOND_CARD].value == BLACKJACK) {
        player->balance += player->bet[idx] * 2.5;
        blackjack_player();
    } else if (player->points[idx] > BLACKJACK) {
        burst_player();
    } else if (dealer->hand[FIRST_CARD].value + dealer->hand[SECOND_CARD].value == BLACKJACK) {
        blackjack_dealer();
    } else if (dealer->points > BLACKJACK) {
        player->balance += player->bet[idx] * 2;
        burst_dealer();
    } else if (player->points[idx] == dealer->points) {
        player->balance += player->bet[idx];
        push();
    } else if (player->points[idx] > dealer->points) {
        player->balance += player->bet[idx] * 2;
        player_win();
    } else {
        player_lose();
    }
    show_balance(player);
    _reset_actions();
}
