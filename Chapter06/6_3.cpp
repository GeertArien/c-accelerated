/**
Accelerated C++, Exercise 6-3, 6_3.cpp

What does this program fragment do?

    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());

Write a program that contains this fragment, and compile and execute it.
*/

#include "stdafx.h"

#include "6_3.h"

#include <vector>
using std::vector;

using std::copy;

int ex6_3()
{
  vector<int> u(10, 100);
  vector<int> v;
  copy(u.begin(), u.end(), v.begin());

  return 0;
}