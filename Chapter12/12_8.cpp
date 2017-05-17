/**
Accelerated C++, Exercise 12_8, 12_8.cpp

Add the getline function to the Str class.
*/

#include "stdafx.h"
#include "12_8.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_8()
{
  Str_c input;

  while (getline(std::cin, input))
    cout << input << endl;

  return 0;
}