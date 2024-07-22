// birdhouse.cpp

#include <fstream>
#include <vector>
#include <iostream>
#include "birdhouse.h"

birdhouse::birdhouse(string FileName) {
    ifstream file(FileName + ".txt");       //actually opens the file
    vector<string> tempWords(100); // just made it so that it stores the words temporarily //was going to make it dynamic to store any amount of numbers but i decided to follow the instructions

    string word;
    int count = 0;  // just a count for the words

    //reading them from the file
    while (file >> word) {
        tempWords[count] = word;  //adding each word to the vector
        count++; //increments it by 1
    }

    file.close(); //closes the file

    //next were going to allocate the memory for wordlist based on the number of words

    wordlist = new string[count];
    NumWords = count; // set NumWords to the number of words in the list

    for (int i =0; i < count; i++) {          //copying the words from the temporary vector to the word list
        wordlist[i] = tempWords[i];
    }
}

birdhouse::~birdhouse() {
    delete[] wordlist;

    randomWord = "";
    NumWords =0;
    numGuess = 0;           //setting them to zero as per the instructions
    uInput = '\0';
    wordLength = 0;
}

void birdhouse::selectRandomWord() {
    int randomIndex = rand() % NumWords; // generate a random index
    randomWord = wordlist[randomIndex]; // select the word at the random index
    wordLength = randomWord.length(); // set wordLength to the length of the chosen word
    userGuess = string(wordLength, '_'); // Initialize userGuess with underscores
}

unsigned short int birdhouse::getWordLength() { // Add this method
    return wordLength;
}

void birdhouse::guessLetter(char letter) {
    bool correctGuess = false;
    for (int i = 0; i < wordLength; i++) {
        if (randomWord[i] == letter) {
            userGuess[i] = letter;
            correctGuess = true;
        }
    }
    if (!correctGuess) {
        numGuess++;
    }
    displayBirdhouse(); // Display the birdhouse after each guess
}

bool birdhouse::isGameOver() {
    return numGuess >= 8 || userGuess == randomWord;
}

string birdhouse::getUserGuess() {
    return userGuess;
}

void birdhouse::displayBirdhouse() {
    string stages[4] = {
        "",
        "  /\\\n /  \\\n",
        "  /\\\n /  \\\n ----\n",
        "  /\\\n /  \\\n ----\n|    |\n"
    };
    cout << stages[numGuess] << endl;
}
