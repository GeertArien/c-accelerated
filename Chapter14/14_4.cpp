/**
Accelerated C++, Exercise 14-4, 14_4.cpp

Reimplement the Str class to use the final version of Ptr.
*/

#include "stdafx.h"
#include "14_4.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "str.h"

int ex14_4()
{
  Str s1 = "Hello ";
  Str s2;
  cout << "Please enter your name: ";
  cin >> s2;
  Str s3 = s1 + s2 + " how are you?";
  cout << s3 << endl;

  return 0;
}