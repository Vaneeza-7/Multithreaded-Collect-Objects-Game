# Multithreaded Collect Objects Game

This is a multithreaded collect objects game implemented in C++ using pthread library. The game allows two players to collect objects on a game board using different controls. The objective of the game is to collect the maximum number of objects to win.

## Game Rules

1. The game board is a grid-based canvas with a specified width and height.
2. Players control their characters using specific keys (arrow keys and shift key for Player 1, and ASDW keys and spacebar for Player 2).
3. Players can move their characters in four directions: up, down, left, and right.
4. Objects are randomly distributed on the game board and can be collected by moving the character over them.
5. Each collected object increases the player's score.
6. The game displays the scores of both players on the screen.
7. The game ends when a certain condition is met (e.g., a time limit or a specific number of objects collected).
8. The player with the highest score at the end of the game wins.

## Installation

1. Clone the repository to your local machine.
2. Compile the source code using a C++ compiler.
3. Run the executable file to start the game.

## Controls

- Player 1 controls:
  - Arrow keys: Move the character up, down, left, or right.
  - Shift key: Collect objects.

- Player 2 controls:
  - ASDW keys: Move the character up, down, left, or right.
  - Spacebar: Collect objects.

## Dependencies

- OpenGL library
- pthread library

Make sure to have the necessary libraries installed before compiling and running the game.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

- The game is inspired by classic collect objects games.
