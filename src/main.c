#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "save.h"

extern bool g_split;

static void _check_args(int ac, char **av) {
    if (ac != 2) {
        dprintf(2, "Usage: %s file_name\n", av[0]);
        exit(1);
    }
}

int main(int ac, char **av) {
    deck_s deck;
    player_s player;
    dealer_s dealer;
    int64_t balance[NB_GAME + 1];

    _check_args(ac, av);

    player.balance = 100000000;
    player.lose_strick = 0;
    balance[0] = player.balance;

    srand(time(NULL));

    for (int i = 0; i < NB_GAME; i++) {
        init_turn(&deck, &player, &dealer);
        bet(&player, FIRST_HAND);
        player.balance -= player.bet[FIRST_HAND];
        distribute(&deck, &player, &dealer);
        play_turn(&deck, &player, &dealer);
        announce_results(&player, &dealer, FIRST_HAND);
        if (g_split) {
            g_split = false;
            announce_results(&player, &dealer, SECOND_HAND);
        }
        balance[i + 1] = player.balance;
    }

    save_balance_data(balance, av[1]);

    return 0;
}
