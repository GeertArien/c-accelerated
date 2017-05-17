/**
Accelerated C++, Exercise 12_10, 12_10.cpp

Having seen in §12.1/212 how Str defined a constructor that takes a pair of
iterators, we can imagine that such a constructor would be useful in class Vec. Add this
constructor to Vec, and reimplement Str to use the Vec constructor instead of calling
copy.
*/

#include "stdafx.h"
#include "12_10.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "str.h"

int ex12_10()
{
  string greeting = "Hello buddy, how are you doing?";

  Str str(greeting.begin(), greeting.end());
  cout << str << endl;

  return 0;
}