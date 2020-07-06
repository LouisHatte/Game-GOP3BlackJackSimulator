#include <stdlib.h>

#include "person.h"
#include "action.h"
#include "deck.h"



#define DEALER_THRESHOLD    16

void    dealer_turn(deck_s* deck, dealer_s* dealer) {
    while (dealer->points <= DEALER_THRESHOLD) {
        pick_card(deck, dealer, NULL);
    }
}
