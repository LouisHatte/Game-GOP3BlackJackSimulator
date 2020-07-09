#include <stdint.h>

#include "game.h"
#include "bet.h"

const int64_t g_bet[NB_BET] = {
    BET_1, BET_1, BET_1, BET_1, // -4K
    BET_2, // -9K
    BET_3, // -19K
    BET_4, // -44K
    BET_5, // -94K
    BET_6, // -194K
    BET_7, // -444K
    BET_8, BET_8, BET_8, BET_8, // -2.444M
    BET_9, BET_9, BET_9, // -9.944M
    BET_10, BET_10, BET_10, BET_10 // -49.944M
};
