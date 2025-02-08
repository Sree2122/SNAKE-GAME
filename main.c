#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main() {
    srand(time(NULL)); // Seed the random number generator
    Game *game = create_game();
    run_game(game);
    free_game(game);
    return 0;
}