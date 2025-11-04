#ifndef GAME_H
#define GAME_H

#include "Leaderboard.h"
#include <chrono>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

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
