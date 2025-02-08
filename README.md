# Simple Snake Game in C

This repository contains a simple snake game implemented in C using the console for display.

## Usage

1. Clone the repository: `git clone https://github.com/your_username/snake_game_c.git`
2. Navigate to the directory: `cd snake_game_c`
3. Compile the code: `make` (or `gcc main.c snake.c game.c -o snake`)
4. Run the game: `./snake`

## Controls

- **Up Arrow:** Move snake up
- **Down Arrow:** Move snake down
- **Left Arrow:** Move snake left
- **Right Arrow:** Move snake right

## Game Rules

- The player controls a snake that moves around the screen.
- The goal is to eat the food (represented by 'F').
- Eating food makes the snake grow longer.
- The game ends if the snake hits the walls or itself.

## Dependencies

- For Windows: `conio.h` (usually included with most C compilers on Windows)
- For Linux/macOS: `termios.h` (for non-blocking input - you'll need to adapt the `handle_input` function)

## Building on Linux/macOS

If you're on Linux/macOS, you'll need to replace the `conio.h` includes and the `_kbhit()` and `_getch()` functions in `game.c` with the appropriate `termios.h` functions for non-blocking input.  You'll also need to change `system("cls")` to `system("clear")` in the `draw_game` function.

## Contributing

Contributions are welcome!

## License

[Choose a license, e.g., MIT]
