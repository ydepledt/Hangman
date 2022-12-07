#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits>

#include "algorithm"

enum LANGUAGE   {FRENCH, ENGLISH};
enum DIFFICULTY {EASY, MEDIUM, HARD, EXTREME};

void stringToLower             (std::string & s);
int  checkStringBool           (std::string s);
int  randomNumber              (int sup, int inf = 0);
void createAllFilesTXT         (LANGUAGE language, std::string const & bigFilePath);
int  transformDifficultyInLimit(DIFFICULTY difficulty);

std::istream& operator>>(std::istream& flow, DIFFICULTY & difficulty);
std::istream& operator>>(std::istream& flow, LANGUAGE & language);

template <typename T, typename Predicate>
void secureInput(T & var, Predicate predicate = [](T & ) -> bool {return true;})
{
    while (!(std::cin >> var) || !predicate(var))
    {
       if (std::cin.eof())
       {
            throw std::runtime_error("Flow stopped !");
       }
       else if (std::cin.fail())
       {
           std::cout << "Incorrect input" << std::endl;
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       }
       else
       {
           std::cout << "Predicate non respected" << std::endl;
       }
    }
}

#endif