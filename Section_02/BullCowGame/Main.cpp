#include <iostream>
#include <string>

/**
 * Introduces the game.
 */
void PrintIntro();

/**
 * Plays the game, by asking the player a guess and printing it a series of times.
 */
void PlayGame();

/**
 * Asks for a guess and returns it.
 * @return The guess introduced by the player
 */
std::string GetGuess();

/**
 * Application entry point
 */
int main() {
    PrintIntro();
    PlayGame();

    return 0;
}
void PlayGame() {
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 0; i < NUMBER_OF_TURNS; i++) {
        std::cout << "Your guess was: " << GetGuess() << std::endl;
    }
}

void PrintIntro() {
    constexpr int WORD_LENGTH = 6;

    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

std::string GetGuess() {
    std::cout << "Enter your guess: ";
    std::string Guess;
    std::getline(std::cin, Guess);

    return Guess;
}
