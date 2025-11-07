#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

// Stores a player's name and score for the game
class Player {
private:
	string name;
	int score;

public:
	// Constructors
	Player();
	Player(string n, int s);

	// Getters
	string getName() const;
	int getScore() const;

	// Setters
	void setScore(int s);
	void setName(string n);

	// Sorts players by score (highest first)
	bool operator<(const Player& other) const;
};

#endif
