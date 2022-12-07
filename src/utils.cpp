#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "utils.hpp"
#include "File.hpp"

void stringToLower(std::string & s)
{
    std::transform(std::begin(s), std::end(s), std::begin(s), [](char letter) -> char {return std::tolower(letter);});
}

int checkStringBool (std::string s)
{   
    stringToLower(s);

    if      (s == "true"  || s == "yes" || s == "y" || s == "1") return 1; 
    else if (s == "false" || s == "no"  || s == "n" || s == "0") return 0;
    else                                                         return -1; //incorrect form of string
}


int randomNumber(int sup, int inf)
{
    return rand() % sup + inf;
}

int transformDifficultyInLimit(DIFFICULTY difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 20;
        break;
    case MEDIUM:
        return 15;
        break;
    case HARD:
        return 10;
        break;
    case EXTREME:
        return 5;
        break;
    default:
        return 15;
    }
}

std::istream& operator>>(std::istream& flow, DIFFICULTY & difficulty)
{
    std::string diff;
    flow >> diff;

    stringToLower(diff);

    if      (diff == "easy")
        difficulty = EASY;
    else if (diff == "medium")
        difficulty = MEDIUM;
    else if (diff == "hard")
        difficulty = HARD;
    else if (diff == "extreme")
        difficulty = EXTREME;

    return flow;
}

std::istream& operator>>(std::istream& flow, LANGUAGE & language)
{
    std::string lang;
    flow >> lang;

    stringToLower(lang);

    if (lang == "french" || lang == "fr")
        language = FRENCH;
    else if (lang == "english" || lang == "en")
        language = ENGLISH;
    
    return flow;
}

//Useful to create files with words with different nb of letters from a big file that contains all words
void createAllFilesTXT(LANGUAGE language, std::string const & bigFilePath)
{
    std::string   word  {""};
    std::ifstream filePath  {bigFilePath};

    if (filePath) 
    {    
        while(std::getline(filePath, word)) 
        {   
            Settings settings(MEDIUM, language, word.size());
            File fileNew(settings);
            std::string   nameFile = fileNew.generateFilePath();
            std::ofstream file {nameFile, std::ios::app};
            file << word << '\n';
        }
        filePath.close();
    }
    else std::cout << "File doesn't exist !" << std::endl;
}