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
// void createAllFilesTXT         (LANGUAGE language, std::string const & bigFilePath);
int  transformDifficultyInLimit(DIFFICULTY difficulty);

std::istream& operator>>(std::istream& flow, DIFFICULTY & difficulty);
std::istream& operator>>(std::istream& flow, LANGUAGE & language);

template <typename T, typename Predicate, typename Predicate2>
void secureInput(T & var, Predicate predicate, Predicate2 predicate2)
{
    while (!(std::cin >> var) || !predicate(var) || !predicate2(var))
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
           std::cout << "Predicates non respected" << std::endl;
       }
    }
}

template <typename T, typename Predicate>
void secureInput(T & var, Predicate predicate)
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
           std::cout << "Predicates non respected" << std::endl;
       }
    }
}

template <typename T>
void secureInput(T & var)
{
    while (!(std::cin >> var))
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
    }
}

#endif