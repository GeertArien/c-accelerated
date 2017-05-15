/**
Accelerated C++, Exercise 12-2, 12_2.cpp

Implement the c_str, data, and copy functions.
*/

#include "stdafx.h"
#include "12_2.h"

#include <iostream>
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_2()
{
  Str_c str = "Aviation industry";
  const char *data = str.data();

  for (size_t i = 0; i < str.size(); i++)
    cout << data[i];
  cout << endl;

  const char *c = str.c_str();

  cout << c << endl;

  char copied[8];
  str.copy(copied, sizeof(copied));

  for (size_t i = 0; i < sizeof(copied); i++)
    cout << copied[i];
  cout << endl;

  return 0;
}