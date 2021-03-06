#include "tabler.h"

const tabler_s g_tabler = {
    .split = {
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N' },
        { '0', '0', 'N', 'N', 'N', 'Y', 'Y', 'N', 'N', 'N', 'N', 'N' },
        { '0', '0', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N', 'N' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'N', 'N' },
        { '0', '0', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N' },
        { '0', '0', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y' }
    },
    .soft = {
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'S', 'D', 'D', 'D', 'D', 'S', 'S', 'H', 'H', 'H' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' }
    },
    .hard = {
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H' },
        { '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D' },
        { '0', '0', 'H', 'H', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' },
        { '0', '0', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S' }
    }
};
