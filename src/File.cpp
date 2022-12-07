#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cassert>

#include "File.hpp"

File::File(std::string const & filePath) : m_language(FRENCH), 
                                           m_nbOfLetters(2), 
                                           m_filePath(filePath) 
{
    assert((m_language == FRENCH || m_language == ENGLISH) && "Language not correct");
}

File::File(Settings settings) : m_language(settings.getLanguage()), 
                                m_nbOfLetters(settings.getNbOfLetters()),
                                m_filePath(this->generateFilePath()) {}


int File::nbOfWordsInFile()
{
    int           count {0};
    std::string   word  {""};
    std::ifstream file  {m_filePath};

    if (file) 
    {    
        while(std::getline(file, word)) 
        {   
            ++count;
        }
        file.close();
    }

    else std::cout << "File doesn't exist !" << std::endl;

    return count;
}

std::string File::generateNameFile()
{
    return std::to_string(m_nbOfLetters) + "_letters.txt";
}

std::string File::generateLanguageFile()
{
    switch (m_language)
    {
    case FRENCH:
        return "french/";
        break;
    case ENGLISH:
        return "english/";
        break;
    default:
        return "french/";
        break;
    }
}

std::string File::generateFilePath()
{
    return "../../../words/" + this->generateLanguageFile() + this->generateNameFile();
}

std::string File::getWordFromFile(int position)
{

    assert(m_filePath != "" && "File path can't be \"\"");

    std::string   word  {""};
    std::ifstream file  {m_filePath};

    if (file) 
    {    
        for (int i = 0; i < position; ++i)
        {
            std::getline(file, word);
        }
        file.close();
    }
    else std::cout << "File doesn't exist !" << std::endl;

    return word;
}

std::string File::getRandomWord()
{
    int         randNumber {};
    std::string randomWord {};

    randNumber = randomNumber(this->nbOfWordsInFile());
    randomWord = this->getWordFromFile(randNumber);

    return randomWord;
}