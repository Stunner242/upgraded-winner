#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Options { Rock, Paper, Scissors };

Options user() {
    char input;
    cout << "Enter your Choice to proceed: (R- Rock, P- Paper, S- Scissors): ";
    cin >> input;

    input = toupper(input);
    while (input != 'R' && input != 'P' && input != 'S') {
        cout << "Invalid input. Please try again: ";
        cin >> input;
        input = toupper(input);
    }

    switch (input) {
        case 'R':
            return Rock;
        case 'P':
            return Paper;
        case 'S':
            return Scissors;
        default:
            return Rock; 
    }
}

Options comp() {
    srand(time(0)); 
    int random_num = rand() % 3;
    return static_cast<Options>(random_num);
}

int winner(Options user, Options comp) {
    if (user == comp) {
        return 0; 
    } else if ((user == Rock && comp == Scissors) ||
              (user == Paper && comp == Rock) ||
              (user == Scissors && comp == Paper)) {
        return 1; 
    } else {
        return -1; 
    }
}

int main() {
    int userScore = 0;
    int compScore = 0;
    char playAgain;

    do {
        cout << "Welcome to Rock, Paper, Scissors\n";

        Options userChoice = user();
        Options compChoice = comp();

        cout << "Your choice: " << (userChoice == Rock ? "Rock" : (userChoice == Paper ? "Paper" : "Scissors")) << endl;
        cout << "Computer's choice: " << (compChoice == Rock ? "Rock" : (compChoice == Paper ? "Paper" : "Scissors")) << endl;

        int result = winner(userChoice, compChoice);
        if (result == 0) {
            cout << "Tie!" << endl;
        } else if (result == 1) {
            cout << "You win!" << endl;
            userScore++;
        } else {
            cout << "You lose!" << endl;
            compScore++;
        }

        cout << "Your score: " << userScore << ", Computer score: " << compScore << endl;

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (toupper(playAgain) == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
