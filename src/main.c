#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "deck.h"
#include "person.h"
#include "game.h"
#include "action.h"

#include <stdio.h>

int main(void) {
    deck_s deck;
    player_s player;
    dealer_s dealer;

    // Set your initial player balance here
    player.balance = 29000000;

    srand(time(NULL));

    for (int i = 0; i < NB_GAME; i++) {
        init_turn(&deck, &player, &dealer);
        bet(&player);
        player.balance -= player.bet;
        distribute(&deck, &player, &dealer);
        game_loop(&deck, &player, &dealer);
        exit(0);
    }

    return 0;
}
