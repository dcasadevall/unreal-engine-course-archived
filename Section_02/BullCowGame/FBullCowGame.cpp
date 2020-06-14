//
// Created by Daniel Casadevall Pino on 2020-06-14.
//

#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(int WordLength, int MaxAttempts) {
    this->WordLength = WordLength;
    this->MaxAttempts = MaxAttempts;
}

int FBullCowGame::GetMaxAttempts() const {
    return MaxAttempts;
}

int FBullCowGame::GetCurrentAttempt() const {
    return CurrentAttempt;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::SubmitGuess(std::string) {
    CurrentAttempt++;
    return false;
}

#pragma region Private
std::string FBullCowGame::CheckGuessValidity(std::string) {
    return std::string();
}

bool FBullCowGame::IsIsogram(std::string) {
    return false;
}
#pragma endregion Private