/**
Accelerated C++, Exercise 1-6, 1_6.cpp

What does the following program do if, when it asks you for input, you type two
names (for example, Samuel Beckett)? Predict the behavior before running the program,
then try it.

    #include <iostream>
    #include <string>
    int main()
    {
      std::cout << "What is your name? ";
      std::string name;
      std::cin >> name;
      std::cout << "Hello, " << name
                << std::endl << "And what is yours? ";
      std::cin >> name;
      std::cout << "Hello, " << name
                << "; nice to meet you too!" << std::endl;
      return 0;
    }
*/

#include "stdafx.h"
#include "1_6.h"

#include <iostream>
#include <string>

int ex1_6()
{
  std::cout << "What is your name? ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name
    << std::endl << "And what is yours? ";
  std::cin >> name;
  std::cout << "Hello, " << name
    << "; nice to meet you too!" << std::endl;
  return 0;
}