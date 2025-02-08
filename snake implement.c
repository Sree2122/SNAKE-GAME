#include <stdlib.h>
#include "snake.h"

void initialize_snake(Snake *snake, int start_x, int start_y) {
    snake->length = 1;
    snake->body[0].x = start_x;
    snake->body[0].y = start_y;
    snake->dx = 1;  // Start moving right
    snake->dy = 0;
}

void move_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1]; // Move body segments
    }
    snake->body[0].x += snake->dx;
    snake->body[0].y += snake->dy;
}

int check_collision(const Snake *snake, int width, int height) {
    if (snake->body[0].x < 0 || snake->body[0].x >= width ||
        snake->body[0].y < 0 || snake->body[0].y >= height) {
        return 1; // Collision with walls
    }
    return 0;
}

int check_self_collision(const Snake *snake) {
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x &&
            snake->body[0].y == snake->body[i].y) {
            return 1; // Self-collision
        }
    }
    return 0;
}