#ifndef GAME_H
#define GAME_H

#include "Leaderboard.h"  
#include <chrono>          // Used for precise timing (measuring quiz duration)
#include <climits>         // Provides INT_MAX for input validation limits
#include <cstdlib>         // Used for rand(), srand()
#include <iostream>        // Used for cin and cout
#include <fstream>         // Used for file input/output (saving score data)
#include <cctype>          // Provides character classification functions (isalpha, isdigit)

using namespace std; 

// Handles gameplay logic and leaderboard updates
class Game {
private:
	// Leaderboard manager
	Leaderboard leaderboard;

	// Checks for valid user input
	int ErrorChecker(int input);

	// Returns range for chosen difficulty
	int getDifficultyRange();

	// Computes final score
	int calculateScore(int correct, int seconds, int difficulty);

public:
	// Constructor
	Game();

	// Main menu loop
	void menu();

	// Runs one full round of the game
	Player playRound();
};

#endif
