//
// Created by Daniel Casadevall Pino on 2020-06-13.
//

#ifndef SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_
#define SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_

#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
  public:
    explicit FBullCowGame(int32 WordLength, int32 MaxAttempts);

    int32 GetMaxAttempts() const;
    int32 GetCurrentAttempt() const;
    bool IsGameWon() const;

    bool SubmitGuess(FString);
    // Provide method for counting bulls and cows and increasing turn #

  private:
    int32 WordLength;
    int32 MaxAttempts;
    int32 CurrentAttempt;

    bool IsIsogram(FString);
    FString CheckGuessValidity(FString);
};

#endif //SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_
