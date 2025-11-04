#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <set>
#include <iostream>
#include <algorithm>
#include "Player.h"

// Tracks players and their best scores
class Leaderboard {
private:
	// Stores players sorted by score and name
	set<Player> players;

public:
	// Adds or updates a player's score
	void addOrUpdatePlayer(const Player& p);

	// Displays all player scores
	void display() const;
};

#endif
