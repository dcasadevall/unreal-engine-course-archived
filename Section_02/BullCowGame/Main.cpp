/**
 * This is the console executable that uses the BullCow class.
 * It's responsible for presenting the "UI" to the user to interact with our BullCow model.
 */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

/**
 * Introduces the game.
 */
void Print32Intro(int32 WordLength);

/**
 * Plays the game, by asking the player a guess and print32ing it a series of times.
 */
void PlayGame(FBullCowGame Game, int32 ExpectedWordLength);

/**
 * Asks for a guess and returns it.
 * @return The guess int32roduced by the player
 */
FText GetGuess();

/**
 * Prints the reason for an invalid guess.
 */
void PrintInvalidGuessReason(EGuessStatus GuessStatus, int32 ExpectedWordLength);

/**
 * Asks the player if they want to play again.
 * @return True if the player said yes. False otherwise.
 */
bool AskToPlayAgain();

/**
 * Application entry point32
 */
int main() {
    const FString HIDDEN_WORD = "planet";
    constexpr int32 MAX_ATTEMPTS = 8;

    FBullCowGame BCGame = FBullCowGame(HIDDEN_WORD, MAX_ATTEMPTS);

    do {
        Print32Intro(HIDDEN_WORD.length());
        PlayGame(BCGame, HIDDEN_WORD.length());
    } while (AskToPlayAgain());

    return 0;
}

void Print32Intro(const int32 WordLength) {
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WordLength << " letter isogram I'm thinking of?\n";
}

void PlayGame(FBullCowGame Game, int32 ExpectedWordLength) {
    // TODO Change from for to while loop once we validate tries
    for (int32 i = 0; i < Game.GetMaxAttempts(); i++) {
        FText Guess = GetGuess();
        EGuessStatus GuessStatus = Game.CheckGuessValidity(Guess);
        if (GuessStatus != EGuessStatus::OK) {
            PrintInvalidGuessReason(GuessStatus, ExpectedWordLength);
            continue;
        }

        FBullCowCount BullCowCount = Game.SubmitGuess(Guess);
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << BullCowCount.Bulls << " Bulls. " << BullCowCount.Cows << " Cows.\n";
    }
}

FText GetGuess() {
    std::cout << "Enter your guess: ";
    FText Guess;
    std::getline(std::cin, Guess);

    return Guess;
}

void PrintInvalidGuessReason(EGuessStatus GuessStatus, int32 ExpectedWordLength) {
    FText Reason;
    switch(GuessStatus) {
        case EGuessStatus::Not_Lowercase:
            Reason = "Please enter an all lowercase word";
            break;
        case EGuessStatus::Incorrect_Length:
            Reason = "Please enter a " + std::to_string(ExpectedWordLength) + " letter word";
            break;
        case EGuessStatus::Not_Isogram:
            Reason = "Please enter an isogram as a guess (no repeated letters)";
            break;
        default:
            return;
    }

    std::cout << Reason << std::endl;
}

bool AskToPlayAgain() {
    FText Response;
    std::cout << "Do you want to play again (y/n)? ";
    std::getline(std::cin, Response);

    return Response.length() > 0 && (Response[0] == 'y' || Response[0] == 'Y');
}
