/**
Accelerated C++, Exercise 2-6, 2_6.cpp

What does the following code do?

    int i = 0;
    while (i < 10) {
      i += 1;
      std::cout << i << std::endl;
    }
*/

#include "stdafx.h"
#include "2_6.h"

#include <iostream>

int ex2_6()
{
  int i = 0;

  while (i < 10) 
  {
    i += 1;
    std::cout << i << std::endl;
  }

  return 0;
}