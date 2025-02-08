#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _kbhit() and _getch() (Windows) - use termios for Linux/macOS
#include "game.h"

Game *create_game() {
    Game *game = (Game *)malloc(sizeof(Game));
    initialize_snake(&game->snake, WIDTH / 2, HEIGHT / 2);
    generate_food(game);
    game->game_over = 0;
    return game;
}

void run_game(Game *game) {
    while (!game->game_over) {
        handle_input(game);
        update_game(game);
        draw_game(game);
        // Add a small delay here for smoother gameplay (e.g., using sleep() or usleep())
        // For Windows: _sleep(100); // 100 milliseconds
    }
    printf("Game Over!\n");
}

void handle_input(Game *game) {
    if (_kbhit()) { // Check if a key was pressed
        int key = _getch(); // Get the key code
        switch (key) {
            case 72: // Up arrow
                if (game->snake.dy != 1) { // Prevent going directly down
                    game->snake.dx = 0;
                    game->snake.dy = -1;
                }
                break;
            case 80: // Down arrow
                if (game->snake.dy != -1) { // Prevent going directly up
                    game->snake.dx = 0;
                    game->snake.dy = 1;
                }
                break;
            case 75: // Left arrow
                if (game->snake.dx != 1) { // Prevent going directly right
                    game->snake.dx = -1;
                    game->snake.dy = 0;
                }
                break;
            case 77: // Right arrow
                if (game->snake.dx != -1) { // Prevent going directly left
                    game->snake.dx = 1;
                    game->snake.dy = 0;
                }
                break;
        }
    }
}

void update_game(Game *game) {
    move_snake(&game->snake);

    if (check_collision(&game->snake, WIDTH, HEIGHT) || check_self_collision(&game->snake)) {
        game->game_over = 1;
        return;
    }

    if (game->snake.body[0].x == game->food.x && game->snake.body[0].y == game->food.y) {
        game->snake.length++; // Grow snake
        generate_food(game);  // Generate new food
    }
}

void draw_game(const Game *game) {
    system("cls"); // Clear the console (Windows) - use "clear" for Linux/macOS
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int is_snake = 0;
            for (int i = 0; i < game->snake.length; i++) {
                if (game->snake.body[i].x == x && game->snake.body[i].y == y) {
                    printf("O"); // Snake body
                    is_snake = 1;
                    break;
                }
            }
            if (game->food.x == x && game->food.y == y) {
                printf("F"); // Food
            } else if (!is_snake) {
                printf("."); // Empty space
            }
        }
        printf("\n");
    }
}

void generate_food(Game *game) {
    game->food.x = rand() % WIDTH;
    game->food.y = rand() % HEIGHT;
}

void free_game(Game *game) {
    free(game);
}