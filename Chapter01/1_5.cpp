/**
Accelerated C++, Exercise 1-5, 1_5.cpp

Is this program valid? If so, what does it do? If not, say why not, and rewrite it to
be valid.

    #include <iostream>
    #include <string>
    int main()
    {
      { std::string s = "a string";
      { std::string x = s + ", really";
      std::cout << s << std::endl; }
      std::cout << x << std::endl;
      }
      return 0;
    }
*/

#include "stdafx.h"
#include "1_5.h"

#include <iostream>
#include <string>

int ex1_5()
{
  { 
    std::string s = "a string";
    { 
      std::string x = s + ", really";
      std::cout << s << std::endl;
      std::cout << x << std::endl;
    }
    // x is undefined in current scope
    // std::cout << x << std::endl;
  }
  return 0;
}