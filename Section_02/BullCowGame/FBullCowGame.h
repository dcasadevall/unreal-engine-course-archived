//
// Created by Daniel Casadevall Pino on 2020-06-13.
//

#ifndef SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_
#define SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_

#include <string>

class FBullCowGame {
  public:
    explicit FBullCowGame(int WordLength, int MaxAttempts);
    int GetMaxAttempts() const;
    int GetCurrentAttempt() const;
    bool IsGameWon() const;
    bool SubmitGuess(std::string);

  private:
    int WordLength;
    int MaxAttempts;
    int CurrentAttempt = 1;
    bool IsIsogram(std::string);
    std::string CheckGuessValidity(std::string);
};

#endif //SECTION_02_BULLCOWGAME_FBULLCOWGAME_H_
