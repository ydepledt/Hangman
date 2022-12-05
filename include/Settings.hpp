#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <iostream>

#include "utils.hpp"

class Settings {

    public:
        Settings() = delete;
        Settings(DIFFICULTY difficulty, LANGUAGE language = FRENCH, int numberOfLetters = 5);

        DIFFICULTY getDifficulty()  {return m_difficulty;};
        LANGUAGE   getLanguage()    {return m_language;};
        int        getNbOfLetters() {return m_numberOfLetters;};

    private:
        DIFFICULTY m_difficulty;
        LANGUAGE   m_language;
        int        m_numberOfLetters;
};

#endif