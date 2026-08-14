# Tic-Tac-Toe Game in C++

A 2-player console-based Tic-Tac-Toe game developed in C++ as part of the Workora C++ Programming Virtual Internship.

## Features

- 2-player gameplay using X and O
- 3x3 character array board
- Dynamic board rendering
- Turn switching between players
- Input validation
- Occupied-position validation
- Row, column, and diagonal win detection
- Draw detection

## Concepts Used

- 2D arrays
- Classes and objects
- Loops
- Conditional statements
- Functions
- Input validation

## How to Run

### Compile

```bash
g++ tic_tac_toe.cpp -o tic_tac_toe
```

### Execute

Windows:

```powershell
.\tic_tac_toe.exe
```

## Game Controls

Players enter a position from 1 to 9:

```text
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
```

Player X goes first, followed by Player O.

## Win Conditions

A player wins by getting three matching symbols in:

- Any row
- Any column
- Main diagonal
- Opposite diagonal

If all positions are filled without a winner, the game ends in a draw.

## Internship

Developed as part of the **Workora C++ Programming Virtual Internship**.

**Intern ID:** WKR-JUL26TOAUG26-517