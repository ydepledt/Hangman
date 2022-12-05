#ifndef WORD_HPP
#define WORD_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Word {

    public:
        Word();
        Word(std::string const & word);

        int  length() {return m_len;};
        bool letterInWord(char letter);
        bool wordFound() {return std::find(std::begin(m_mask), std::end(m_mask), false) == std::end(m_mask);};
        void printLetterFound();
        
        friend std::ostream& operator<<(std::ostream & flow, Word const & word);
        
    private:
        std::string       m_word;
        int               m_len;
        std::vector<bool> m_mask;   
};

#endif