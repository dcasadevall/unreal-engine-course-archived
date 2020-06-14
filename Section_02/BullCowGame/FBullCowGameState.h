//
// Created by Daniel Casadevall Pino on 2020-06-14.
//

#ifndef SECTION_02_BULLCOWGAME_FBULLCOWGAMESTATE_H_
#define SECTION_02_BULLCOWGAME_FBULLCOWGAMESTATE_H_

#import <string>

class FBullCowGameState {
  public:
    int GetNumberOfAttempts();
    std::string GetHiddenWord();

  private:
    int NumberOfAttempts;
    std::string HiddenWord;
};

#endif //SECTION_02_BULLCOWGAME_FBULLCOWGAMESTATE_H_
