#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Player.h"

using namespace std;

class Leaderboard {
private:
    set<Player> topScores;         // keeps only the highest unique score per player
    multiset<Player> allAttempts;  // keeps all scores (duplicates allowed)

public:
    void addAttempt(const Player& p);                      // adds a new score attempt
    void display() const;                                  // shows top unique leaderboard
    void saveAllAttemptsToFile(const string& filename) const;  // saves all scores to file
};

#endif
