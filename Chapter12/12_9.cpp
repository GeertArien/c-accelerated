/**
Accelerated C++, Exercise 12_9, 12_9.cpp

Use class ostream_iterator to reimplement the Str output operator. Why
didn't we ask you to reimplement the input operator using class istream_iterator?
*/

#include "stdafx.h"
#include "12_9.h"

#include <iostream>
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_9()
{
  Str_c s = "Fantastic news!";
  cout << s << endl;

  return 0;
}