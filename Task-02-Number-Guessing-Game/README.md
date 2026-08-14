# Number Guessing Game in C++

A console-based number guessing game developed in C++ as part of the Workora C++ Programming Virtual Internship.

## Features

- Generates a random number between 1 and 100
- Provides "Too High" and "Too Low" hints
- Tracks the number of attempts
- Calculates a score based on attempts
- Supports replaying the game
- Handles invalid non-numeric input
- Provides a clean exit option

## Technologies Used

- C++
- iostream
- cstdlib
- ctime
- Conditional statements
- Loops
- Random number generation

## How It Works

The program seeds the random number generator using the current system time and generates a target number between 1 and 100.

The player continues guessing until the correct number is found. After each guess, the program provides a hint indicating whether the guess is too high or too low.

The final score is calculated based on the number of attempts.

## How to Run

### Compile

```bash
g++ guessing_game.cpp -o guessing_game