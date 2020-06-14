//
// Created by Daniel Casadevall Pino on 2020-06-14.
//

#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(int WordLength, int MaxAttempts) {
    this->WordLength = WordLength;
    this->MaxAttempts = MaxAttempts;
}

int FBullCowGame::GetMaxAttempts() {
    return MaxAttempts;
}

int FBullCowGame::GetCurrentAttempt() {
    return CurrentAttempt;
}

bool FBullCowGame::IsGameWon() {
    return false;
}

std::string FBullCowGame::CheckGuessValidity(std::string) {
    return std::string();
}

bool FBullCowGame::IsIsogram(std::string) {
    return false;
}

std::string FBullCowGame::CalculateResult(std::string) {
    return std::string();
}
