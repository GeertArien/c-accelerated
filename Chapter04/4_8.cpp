/**
Accelerated C++, Exercise 4-8, 4_8.cpp

If the following code is legal, what can we infer about the return type of f?
*/

#include "stdafx.h"
#include "4_8.h"

#include <vector>
using std::vector;

vector<double> f() 
{
  return{ 10.2, 17.5 };
}

int ex4_8()
{
  int n = 1;
  double d = f()[n]; // f() => return vector<double> met minstens n + 1 elementen

  return 0;
}
