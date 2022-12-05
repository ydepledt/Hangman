#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "Word.hpp"
#include "Settings.hpp"
#include "File.hpp"
#include "utils.hpp"

class Game {

    public:
        Game() = delete;
        Game(DIFFICULTY const difficulty, LANGUAGE const language, int const numberOfLetters);

        void initialisation();
        void step();
        bool finished();

        static void askUserSettings(DIFFICULTY & difficulty, LANGUAGE & language, int & numberOfLetters);
        static bool askPlayAgain();

    private:
        int      m_count;
        Settings m_settings;
        File     m_file;
        Word     m_word;
        int      m_limit;

};

#endif