#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>

#include "Settings.hpp"
#include "utils.hpp"

class File {

    public:
        File() = delete;
        File(std::string const & filePath);
        File(Settings settings);

        int         nbOfWordsInFile     ();
        std::string generateNameFile    ();
        std::string generateLanguageFile();
        std::string generateFilePath    ();
        std::string getWordFromFile(int position);
        std::string getRandomWord();

    private:
        LANGUAGE    m_language;
        int         m_nbOfLetters;
        std::string m_filePath;
};

#endif