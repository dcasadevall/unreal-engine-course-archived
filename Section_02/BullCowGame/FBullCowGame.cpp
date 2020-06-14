//
// Created by Daniel Casadevall Pino on 2020-06-14.
//

#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(int32 WordLength, int32 MaxAttempts) {
    this->WordLength = WordLength;
    this->MaxAttempts = MaxAttempts;
    this->CurrentAttempt = 1;
}

int32 FBullCowGame::GetMaxAttempts() const {
    return MaxAttempts;
}

int32 FBullCowGame::GetCurrentAttempt() const {
    return CurrentAttempt;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::SubmitGuess(FString) {
    CurrentAttempt++;
    return false;
}

#pragma region Private
FString FBullCowGame::CheckGuessValidity(FString) {
    return FString();
}

bool FBullCowGame::IsIsogram(FString) {
    return false;
}
#pragma endregion Private