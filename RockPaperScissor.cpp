#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;

enum Choice { Rock, Paper, Scissors };

// Function to get computer's choice (random)
Choice getComputerChoice() {
  // Seed the random number generator (improves randomness)
  srand(time(0));
  // Generate a random number between 1 and 3
  int random_number = rand() % 3;
  // Convert random number to Choice enum
  return static_cast<Choice>(random_number);
}

// Function to get player's choice (validated input)
Choice getPlayerChoice() {
  char input;
  cout << "Enter your choice (R - Rock, P - Paper, S - Scissors): ";
  cin >> input;

  // Validate input (convert to uppercase for easier comparison)
  input = toupper(input);
  while (input != 'R' && input != 'P' && input != 'S') {
    cout << "Invalid input. Please try again: ";
    cin >> input;
    input = toupper(input);
  }

  // Convert valid input to Choice enum
  switch (input) {
    case 'R':
      return Rock;
    case 'P':
      return Paper;
    case 'S':
      return Scissors;
  }
  return Rock; // Should never reach here (compiler may warn)
}

// Function to determine the winner
int determineWinner(Choice playerChoice, Choice computerChoice) {
  if (playerChoice == computerChoice) {
    return 0; // Tie
  } else if ((playerChoice == Rock && computerChoice == Scissors) ||
             (playerChoice == Paper && computerChoice == Rock) ||
             (playerChoice == Scissors && computerChoice == Paper)) {
    return 1; // Player wins
  } else {
    return -1; // Player loses
  }
}

int main() {
  int playerScore = 0;
  int computerScore = 0;

  while (true) {
    Choice computerChoice = getComputerChoice();
    Choice playerChoice = getPlayerChoice();

    cout << "Your choice: " << (playerChoice == Rock ? "Rock" : (playerChoice == Paper ? "Paper" : "Scissors")) << endl;
    cout << "Computer's choice: " << (computerChoice == Rock ? "Rock" : (computerChoice == Paper ? "Paper" : "Scissors")) << endl;

    int result = determineWinner(playerChoice, computerChoice);
    if (result == 0) {
      cout << "Tie!" << endl;
    } else if (result == 1) {
      cout << "You win!" << endl;
      playerScore++;
    } else {
      cout << "You lose!" << endl;
      computerScore++;
    }

    cout << "Your score: " << playerScore << ", Computer score: " << computerScore << endl;

    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;
    if (toupper(playAgain) != 'Y') {
      break;
    }
  }

  cout << "Thanks for playing!" << endl;

  return 0;
}
