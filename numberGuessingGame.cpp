#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));  // Seed the random number generator with the current time

    int secretNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "NUMBER GUESSING GAME\n";
    cout << "Try to guess the secret number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts.\n";
            break;
        }
    } while (true);

    return 0;
}