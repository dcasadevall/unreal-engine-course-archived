//
// Created by Daniel Casadevall Pino on 2020-06-14.
//

#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(const FString& HiddenWord, int32 MaxAttempts) {
    this->CurrentAttempt = 1;

    this->HiddenWord = HiddenWord;
    this->WordLength = HiddenWord.length();
    this->MaxAttempts = MaxAttempts;
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

FBullCowCount FBullCowGame::SubmitGuess(FString) {
    // Increment the turn number
    CurrentAttempt++;

    // Setup a return variable
    FBullCowCount BullCowCount;

    // loop through all letters in guess


    // Compare a letter against the hidden word.
    return BullCowCount;
}

#pragma region Private
FString FBullCowGame::CheckGuessValidity(FString) {
    return FString();
}

bool FBullCowGame::IsIsogram(FString) {
    return false;
}
#pragma endregion Private