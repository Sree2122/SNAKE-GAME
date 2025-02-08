#ifndef GAME_H
#define GAME_H

#include "snake.h"

#define WIDTH 20
#define HEIGHT 15

typedef struct {
    Snake snake;
    Point food;
    int game_over;
} Game;

Game *create_game();
void run_game(Game *game);
void handle_input(Game *game);
void update_game(Game *game);
void draw_game(const Game *game);
void generate_food(Game *game);
void free_game(Game *game);

#endif