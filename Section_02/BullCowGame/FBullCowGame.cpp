//
// Created by Daniel Casadevall Pino on 2020-06-14.
//

#include <set>
#include "FBullCowGame.h"

using uint64 = unsigned long;

FBullCowGame::FBullCowGame(const FString& HiddenWord, int32 MaxAttempts) {
    this->CurrentAttempt = 1;

    this->HiddenWord = HiddenWord;
    this->MaxAttempts = MaxAttempts;
}

int32 FBullCowGame::GetMaxAttempts() const {
    return MaxAttempts;
}

int32 FBullCowGame::GetCurrentAttempt() const {
    return CurrentAttempt;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
    CurrentAttempt++;
    FBullCowCount BullCowCount = FBullCowCount();

    // loop through all letters in guess
    for (uint64 i = 0; i < Guess.length(); i++) {
       for (uint64 j = 0; j < HiddenWord.length(); j++) {
           if (HiddenWord[j] == Guess[i]) {
               if (j == i) {
                   BullCowCount.Bulls++;
               } else {
                   BullCowCount.Cows++;
               }
           }
       }
    }

    // We have found the hidden word if the number of bulls is equal to the word length.
    BullCowCount.IsHiddenWord = BullCowCount.Bulls == HiddenWord.length();

    // Compare a letter against the hidden word.
    return BullCowCount;
}

#pragma region Private
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (!this->IsIsogram(Guess)) {
        return EGuessStatus::Not_Isogram;
    }

    if (!this->IsLengthValid(Guess)) {
        return EGuessStatus::Incorrect_Length;
    }

    if (!this->IsAllLowerCase(Guess)) {
        return EGuessStatus::Not_Lowercase;
    }

    return EGuessStatus::OK;
}

bool FBullCowGame::IsIsogram(const FString& Guess) const {
    std::set<char> charSet;
    for (char GuessCharacter : Guess) {
        if (charSet.find(GuessCharacter) != charSet.end()) {
            return false;
        }

        charSet.insert(GuessCharacter);
    }

    return true;
}

bool FBullCowGame::IsAllLowerCase(const FString& Guess) const {
    for (char GuessCharacter : Guess) {
        if (!std::islower(GuessCharacter)) {
            return false;
        }
    }

    return true;
}

bool FBullCowGame::IsLengthValid(const FString& Guess) const {
    return Guess.length() == HiddenWord.length();
}
#pragma endregion Private