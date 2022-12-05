#include <iostream>
#include <cassert>

#include "Settings.hpp"

Settings::Settings(DIFFICULTY difficulty, LANGUAGE language, int numberOfLetters) : m_difficulty(difficulty), 
                                                                                    m_language(language), 
                                                                                    m_numberOfLetters(numberOfLetters) 
{
    assert((m_difficulty == EASY || m_difficulty == MEDIUM || m_difficulty == HARD || m_difficulty == EXTREME) && "Difficulty not correct");
    assert((m_language == FRENCH || m_language == ENGLISH)                                                     && "Language not correct");

}

