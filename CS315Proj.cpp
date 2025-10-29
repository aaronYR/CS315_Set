/******************************************************************************

CS315 Project
Molly Ruley

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
    // constructor
    Player(string n, int a) : name(n), score(a) {}
} Player;

typedef struct ComparePlayer{
    //custom comparator to compare players
} comparePlayer;

int ErrorChecker(int new_user_input);
void playGame();
//void printLeaderboard();

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
                playGame();
                cout << "Select play and enter your name to try again, ";
                cout<< "or play with a new name.\n";
                break;
            }
            case(2):{
                //printLeaderboard()
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
void playGame(){
    int score;
    string name;
    score = 100 + (rand() % (10000 - 100 + 1)); // min score = 100, max = 10000
    cout <<"Please enter yout name: \n";
    cin >> name;
    cout << "Playing game...\n";
    printf("Congrats you got a score of %d\n", score);
    // if name already exists (strcmp), update score if its better but 
    // if not, create new player
    // add new player and score to the set
    //sort by score, highest first
}

/*void printLeaderboard(){
    for auto in set {
        printf("%s    %d",name, score);
    }
}*/
