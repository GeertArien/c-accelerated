/**
Accelerated C++, Exercise 0-3, 0_3.cpp

The string literal "\t" represents a tab character; different C++ implementations
display tabs in different ways. Experiment with your implementation to learn how it
treats tabs.
*/

#include "stdafx.h"
#include "0_3.h"

#include <iostream>

void ex0_3() 
{
  std::cout << "this is a tab \ttest." << std::endl
    << "\ttab" << std::endl
    << "\ttab \ttest." << std::endl;
}