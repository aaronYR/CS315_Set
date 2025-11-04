/******************************************************************************

CS315 Project
Molly Ruley
Aaron Ybarra

Using sets to implement a leaderboard in C++

*******************************************************************************/
#include <iostream>
#include <string>
#include <set>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <climits>
using namespace std;

typedef struct Player {
    string name;
    int score;
    // default constructor
    Player() : name(""), score(0){}
    // constructor
    Player(string n, int a) : name(n), score(a) {}
} Player;

typedef struct ComparePlayer{
    //custom comparator to compare players
    bool operator()(const Player& p1, const Player& p2){
        return p1.score > p2.score || (p1.score == p2.score && p1.name < p2.name);
    }
} comparePlayer;

// function prototypes
int ErrorChecker(int new_user_input);
Player playGame();
void printLeaderboard(set <Player, comparePlayer> LeaderBoard);

int main()
{
    int choice, loop = 1;
    srand(time(0)); // seed rand
    // create set of players
    set <Player, ComparePlayer>LeaderBoard;
    while (loop){
        cout<<"What would you like to do?\n";
        cout<<"1 - Play the game\n";
        cout<<"2 - Show the leaderboard\n";
        cout<< "3 - Exit\n";
        cin >> choice;
        choice = ErrorChecker(choice);
        switch(choice){
            case(1):{
                Player newPlayer;
                newPlayer = playGame();
                // if name already exists (strcmp), update score if its better but 
                // if not, create new player
                // add new player and score to the set
                LeaderBoard.insert(newPlayer);
                cout << "Select play and enter your name to try again, ";
                cout<< "or play with a new name.\n";
              
                break;
            }
            case(2):{
                printLeaderboard(LeaderBoard);
                break;
            }
            case(3):{
                cout<< "Thanks for playing! Goodbye!\n";
                loop = 0;
                break;
            }
            default: {
                cout<< "Uh oh! That wasn't quite right, try again\n";
                break;
            }
        }
    }
    return 0;
}
// error checker function
int ErrorChecker(int user_input) {
    int new_user_input = user_input;
    while (!cin || new_user_input < 1 || new_user_input > 3 ) { //that was not an number, cin is in error

        cin.clear(); //clear error flag

        cin.ignore(INT_MAX, '\n');

        cout << "Error. Please enter a 1, 2, or 3.\n"; 
        cin >> new_user_input;

    }
    return new_user_input;
}
// function to give player's random scores
Player playGame(){
    int score;
    string name;
    score = 100 + (rand() % (10000 - 100 + 1)); // min score = 100, max = 10000
    cout <<"Please enter your name: \n";
    cin >> name;
    cout << "Playing game...\n";
    cout << "Congrats " <<name << " got a score of " << score << ".\n";
    return Player(name,score);
}

void printLeaderboard(set<Player,ComparePlayer> LeaderBoard){
    cout << "*******LeaderBoard*******\n";
    for (const auto& player : LeaderBoard) {
        cout << player.name << " (" << player.score << ")\n";
    }
}