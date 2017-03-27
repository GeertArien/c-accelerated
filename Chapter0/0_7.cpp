/**
Accelerated C++, Exercise 0-7, 0_7.cpp

What about this one?

    #include <iostream>

    int main()
    {
      /* This is a comment that extends over several lines
         because it uses /* and *(/) as its starting and ending delimiters * /
      std::cout << "Does this work?" << std::endl;
      return 0;
    }
*/

#include "stdafx.h"
#include "0_7.h"

#include <iostream>

// Incorrect use of comment delimiters.
/**
int ex0_7()
{
  /* This is a comment that extends over several lines
  because it uses /* and */ /**as its starting and ending delimiters * /
  std::cout << "Does this work?" << std::endl;
  return 0;
}
*/

int ex0_7()
{
  /* This is a comment that extends over several lines
  because it uses /* and *(/) as its starting and ending delimiters */
  std::cout << "Does this work?" << std::endl;
  return 0;
}