/**
Accelerated C++, Exercise 12_12, 12_12.cpp

Define the insert function that takes two iterators for the Vec and Str
classes.
*/

#include "stdafx.h"
#include "12_12.h"

#include <iostream>
using std::cout;
using std::endl;

#include "str.h"

int ex12_12()
{
  Str greeting = "Hello , how are you?";
  Str name = "Geert";

  greeting.insert(greeting.begin() + 6, name.begin(), name.end());

  cout << greeting << endl;

  return 0;
}