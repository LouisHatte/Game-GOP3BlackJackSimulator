#include <time.h>
#include <stdlib.h>

#include "game.h"
#include "action.h"
#include "player.h"

extern bool g_split;

int main(void) {
    deck_s deck;
    player_s player;
    dealer_s dealer;

    player.balance = 10; // Set your initial player balance here.

    srand(time(NULL));

    for (int i = 0; i < NB_GAME; i++) {
        init_turn(&deck, &player, &dealer);
        bet(&player);
        player.balance -= player.bet[FIRST_HAND];
        distribute(&deck, &player, &dealer);
        play_turn(&deck, &player, &dealer);
        announce_results(&player, &dealer, FIRST_HAND);
        if (g_split) {
            g_split = false;
            announce_results(&player, &dealer, SECOND_HAND);
        }
    }
    return 0;
}
