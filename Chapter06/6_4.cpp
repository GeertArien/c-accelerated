/**
Accelerated C++, Exercise 6-4, 6_4.cpp

Correct the program you wrote in the previous exercise to copy from u into v.
There are at least two possible ways to correct the program. Implement both, and
describe the relative advantages and disadvantages of each approach.
*/

#include "stdafx.h"

#include "6_4.h"

#include <vector>
using std::vector;

using std::copy;

int ex6_4() 
{
  vector<int> u(10, 100);

  //vector<int> v(u);           // Direct initialization as copy of vector u
  //vector<int> v = u;          // Implicit initialization as copy of vector u

  vector<int> v(u.size());      // first initialized with default value
  copy(u.begin(), u.end(), v.begin());

  return 0;
}