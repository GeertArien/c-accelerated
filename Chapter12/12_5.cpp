/**
Accelerated C++, Exercise 12-5, 12_5.cpp

Implement concatenation for Str so as not to rely on conversions from const
char*.
*/

#include "stdafx.h"
#include "12_5.h"

#include <iostream>
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_5()
{
  Str_c name = "Geert";
  Str_c greeting = "Hello, " + name;
  
  cout << greeting << endl;

  Str_c goodbye = name + ", bye!";

  cout << goodbye << endl;

  Str_c complete = "Hello, " + name + " and goodbye!";

  cout << complete << endl;

  return 0;
}