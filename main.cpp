// main.cpp

#include <iostream>
#include "birdhouse.h"
#include <ctime>

using namespace std;

int main() {

    srand(time(0)); // setting the seed for rand

    string filename;
    cout << "Please enter the name of the file you want to open without the extension name:" << endl;
    cin >> filename;

    birdhouse game(filename); // birdhouse object
    game.selectRandomWord();  // random word

    // output asking for the guess and loop
    while (!game.isGameOver()) {
        cout << "Current guess: " << game.getUserGuess() << endl;
        cout << "Enter your guess: ";

        char guess;
        cin >> guess;
        game.guessLetter(guess);
    }

    if (game.getUserGuess() == game.getRandomWord()) {
        cout << "Congrats, you guessed the word correctly." << endl;
    } else {
        cout << "Sorry, you didn't get the word in time. It was " << game.getRandomWord() << endl;
    }

    return 0;
}
