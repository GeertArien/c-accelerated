/**
Accelerated C++, Exercise 12_7, 12_7.cpp

The standard string class provides random-access iterators to manipulate the
string's characters. Add iterators and the iterator operations begin and end to your
Str class.
*/

#include "stdafx.h"
#include "12_7.h"

#include <iostream>
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_7()
{
  Str_c greeting = "Hello buddy!";
  Str_c::const_iterator iter = greeting.begin();

  while (iter != greeting.end())
    cout << *iter++;

  cout << endl;

  return 0;
}