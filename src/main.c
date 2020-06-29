#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "deck.h"
#include "person.h"
#include "game.h"

#include <stdio.h>

int main(void) {
    bj_deck_s deck;
    player_s player;
    dealer_s dealer;

    player.balance = 10000000;

    srand(time(NULL));
    get_deck(&deck);

    for (int i = 0; i < 15; i++) {
        printf("%d: %s of %s: %d\n", i, deck.cards[i].name, deck.cards[i].color, deck.cards[i].value);
    }

    game_loop(&deck, &player, &dealer);

    return 0;
}
