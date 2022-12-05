#include <iostream>
#include <fstream>
#include <ctime>

#include "Game.hpp"
#include "Settings.hpp"
#include "File.hpp"

int main()
{
    srand(time(NULL));
    bool playAgain {false};
    
    do {
        DIFFICULTY difficulty;
        LANGUAGE language;
        int numberOfLetters;

        Game::askUserSettings(difficulty, language, numberOfLetters);
        Game game(difficulty, language, numberOfLetters);
    
        game.initialisation();

        do {

            game.step();

        } while(!game.finished());

        playAgain = Game::askPlayAgain();

    } while(playAgain);

    return 0;
}