#include <iostream>
#include <string>
#include "FBullCowGame.h"

/**
 * Introduces the game.
 */
void PrintIntro(int WordLength);

/**
 * Plays the game, by asking the player a guess and printing it a series of times.
 */
void PlayGame(int WordLength);

/**
 * Asks for a guess and returns it.
 * @return The guess introduced by the player
 */
std::string GetGuess();

/**
 * Asks the player if they want to play again.
 * @return True if the player said yes. False otherwise.
 */
bool AskToPlayAgain();

/**
 * Application entry point
 */
int main() {
    constexpr int WORD_LENGTH = 6;
    PrintIntro(WORD_LENGTH);

    do {
        PlayGame(WORD_LENGTH);
    } while (AskToPlayAgain());

    return 0;
}

void PrintIntro(const int WordLength) {
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WordLength << " letter isogram I'm thinking of?\n";
}

void PlayGame(int WordLength) {
    FBullCowGame BCGame = FBullCowGame(WordLength, 5);

    for (int i = 0; i < BCGame.GetMaxAttempts(); i++) {
        std::string Guess = GetGuess();
        std::cout << "Your guess was: " << Guess << std::endl;
    }
}

std::string GetGuess() {
    std::cout << "Enter your guess: ";
    std::string Guess;
    std::getline(std::cin, Guess);

    return Guess;
}

bool AskToPlayAgain() {
    std::string Response;
    std::cout << "Do you want to play again (y/n)? ";
    std::getline(std::cin, Response);

    return Response.length() > 0 && (Response[0] == 'y' || Response[0] == 'Y');
}
