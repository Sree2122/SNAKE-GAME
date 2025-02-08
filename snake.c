#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point body[MAX_SNAKE_LENGTH];
    int length;
    int dx; // Direction x (-1, 0, 1)
    int dy; // Direction y (-1, 0, 1)
} Snake;

void initialize_snake(Snake *snake, int start_x, int start_y);
void move_snake(Snake *snake);
int check_collision(const Snake *snake, int width, int height);
int check_self_collision(const Snake *snake);

#endif