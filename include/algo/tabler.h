#pragma once

#define NB_HARD_VALUES      22
#define NB_DOUBLE_VALUES    12
#define NB_SOFT_VALUES      11

#define NB_DEALER_VALUES    12

#define HIT     'H'
#define STAND   'S'
#define DOUBLE  'D'
#define SPLIT   'Y'

typedef struct tabler {
    char    split[NB_DOUBLE_VALUES][NB_DEALER_VALUES];
    char    soft[NB_SOFT_VALUES][NB_DEALER_VALUES];
    char    hard[NB_HARD_VALUES][NB_DEALER_VALUES];
} tabler_s;
