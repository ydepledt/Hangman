#include <iostream>
#include <cassert>

#include "Word.hpp"

Word::Word(std::string const & word) : m_word (word), m_len(word.size()), m_mask(word.size(), false)
{
    assert(m_word.size() >= 2 && "Word must have a length >= 2");
}

bool Word::letterInWord(char letter)
{
    bool inWord {false};

    for (int i = 0; i < m_len; ++i)
    {
        if ((char) toupper(letter) == (char) toupper(m_word[i]) && !m_mask[i])
        {
            inWord    = true;
            m_mask[i] = true;
        } 
    }

    return inWord;
}

void Word::printLetterFound()
{
    for (int i = 0; i < this->m_len; ++i) 
        std::cout << ((this->m_mask[i]) ? (char) toupper(this->m_word[i]) : '*');     
}

std::ostream& operator<<(std::ostream & flow, Word const & word)
{
    for (auto m_letter : word.m_word) flow << (char) toupper(m_letter);

    return flow;
}