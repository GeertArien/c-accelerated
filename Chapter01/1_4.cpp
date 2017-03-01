/**
Accelerated C++, Exercise 1-4, 1_4.cpp

What about this one? What if we change }} to };} in the third line from the end?

#include <iostream>
#include <string>

    int main()
    {
      { const std::string s = "a string";
        std::cout << s << std::endl;
      { const std::string s = "another string";
        std::cout << s << std::endl; }}
    return 0;
    }
*/

#include "stdafx.h"
#include "1_4.h"

#include <iostream>
#include <string>

int ex1_4()
{
  { 
    const std::string s = "a string";
    std::cout << s << std::endl;
    { 
      const std::string s = "another string";
      std::cout << s << std::endl; 
    };}
  return 0;
}