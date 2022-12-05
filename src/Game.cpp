#include <iostream>
#include <cassert>

#include "Game.hpp"

Game::Game(DIFFICULTY const difficulty, LANGUAGE const language, int const numberOfLetters) : m_count(0), 
                                                                                              m_settings(difficulty, language, numberOfLetters),
                                                                                              m_file(m_settings),
                                                                                              m_word(m_file.getRandomWord()),
                                                                                              m_limit(transformDifficultyInLimit(difficulty)) {}


void Game::askUserSettings(DIFFICULTY & difficulty, LANGUAGE & language, int & numberOfLetters)
{
    std::cout << "----------------------Welcome to the hangman game----------------------" << std::endl;

    std::cout << "Choose your difficulty : ";
    secureInput(difficulty, [](DIFFICULTY diff) -> bool {return diff == EASY || diff == MEDIUM || diff == HARD || diff == EXTREME;});
    std::cout << std::endl;

    std::cout << "Choose your language (for words) : ";
    secureInput(language, [](LANGUAGE lang) -> bool {return lang == FRENCH || lang == ENGLISH;});
    std::cout << std::endl;
    
    std::cout << "Choose word's number of letters : ";
    secureInput(numberOfLetters, [](int nbOfLet) -> bool {return nbOfLet >= 2 && nbOfLet <= 15;});
    std::cout << std::endl;
}

bool Game::askPlayAgain()
{
    std::string answer    {""}; //easier to test predicate over string rather than bool
    bool        playAgain {false};

    auto predicate = [](std::string answer) -> bool 
    {   
        return (checkStringBool(answer) == 1 || checkStringBool(answer) == 0);   
    };

    std::cout << "Do you want to play again : ";
    secureInput(answer, predicate);
    std::cout << std::endl << std::endl;

    playAgain = (checkStringBool(answer) == 1); //if string is a form of true (like true, yes, y...) then bool is true

    return playAgain;
}

void Game::initialisation()
{
    if (m_limit != -1) std::cout << "You have " << m_limit << " propositions to find the hidden word" << std::endl;
    std::cout << "Good Luck !!!" << std::endl << std::endl;
}

void Game::step()
{
    char letter   {};

    std::cout << "The hidden word is : ";
    m_word.printLetterFound();
    std::cout << std::endl;

    std::string proposition = m_limit-m_count < 2 ? "proposition" : "propositions"; //to write singular or plural
    if (m_limit > 0) std::cout << m_limit-m_count << " remaining " << proposition << std::endl;

    std::cout << "Give a letter : ";
    secureInput(letter, isalpha);
    std::cout << std::endl;

    if (!m_word.letterInWord((char) toupper(letter))) ++m_count;

    std::cout << std::endl << std::endl;
}

bool Game::finished()
{
    if (m_count == m_limit)
    {
        std::cout << "You've lost, the word was : " << m_word << std::endl << std::endl;
        return true;
    }

    if (m_word.wordFound())
    {
        std::string proposition = m_count < 2 ? "proposition" : "propositions"; //to write singular or plural
        std::cout << "You've won, with " << m_count << " wrong " << proposition << ", the word was : " << m_word << std::endl << std::endl;
        return true;
    }

    return false;
}