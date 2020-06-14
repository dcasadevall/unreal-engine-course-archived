//
// Created by Daniel Casadevall Pino on 2020-06-13.
//

#ifndef SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_
#define SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
  public:
    explicit FBullCowGame(const FString& HiddenWord, int32 MaxAttempts);

    int32 GetMaxAttempts() const;
    int32 GetCurrentAttempt() const;
    bool IsGameWon() const;

    /**
     * Counts bulls & cows, and increases attempt #.
     * Assumes valid guess.
     */
    FBullCowCount SubmitGuess(FString);

  private:
    int32 WordLength;
    int32 MaxAttempts;
    int32 CurrentAttempt;
    FString HiddenWord;

    bool IsIsogram(FString);
    FString CheckGuessValidity(FString);
};

#endif //SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_
