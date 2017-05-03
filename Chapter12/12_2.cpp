/**
Accelerated C++, Exercise 12-2, 12_2.cpp

Implement the c_str, data, and copy functions.
*/

#include "stdafx.h"
#include "12_2.h"

#include <string>

int ex12_2()
{
  std::string s = "test";
  size_t i = s.length();
  s.c_str();
  size_t j = s.length();

  return 0;
}