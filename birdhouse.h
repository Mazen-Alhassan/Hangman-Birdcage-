// birdhouse.h

#include <string> // Include this to use string
#include <cstdlib>

using namespace std; // Use this to avoid typing std:: before string

class birdhouse {
public:
    birdhouse(string FileName);
    ~birdhouse();
    void selectRandomWord();
    unsigned short int getWordLength();
    void guessLetter(char letter);
    bool isGameOver();
    string getUserGuess();
    string getRandomWord() {
        return randomWord;
    }
    void displayBirdhouse(); // New method to display the birdhouse
    string userGuess;
private:
    string* wordlist;
    string randomWord;
    unsigned short int NumWords;
    unsigned short int numGuess;
    char uInput;
    unsigned short int wordLength;
};
