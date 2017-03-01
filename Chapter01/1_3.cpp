/**
Accelerated C++, Exercise 1-3, 1_3.cpp

Is the following program valid? If so, what does it do? If not, why not?

    #include <iostream>
    #include <string>
    int main()
    {
      { const std::string s = "a string";
        std::cout << s << std::endl; }

      { const std::string s = "another string";
        std::cout << s << std::endl; }
      return 0;
    }
*/

#include "stdafx.h"
#include "1_3.h"

#include <iostream>
#include <string>

int ex1_3()
{
  { 
    const std::string s = "a string";
    std::cout << s << std::endl; 
  }

  { 
    const std::string s = "another string";
    std::cout << s << std::endl; 
  }

  return 0;
}