#include "person.h"
#include "action.h"

#define DEALER_THRESHOLD    16

void    dealer_turn(bj_deck_s* deck, dealer_s* dealer) {
    while (dealer->points <= DEALER_THRESHOLD) {
        dealer_pick_card(deck, dealer);
    }
}
