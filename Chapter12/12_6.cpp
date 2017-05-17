/**
Accelerated C++, Exercise 12-6, 12_6.cpp

Give Str an operation that will let us implicitly use a Str object as a condition.
The test should fail if the Str is empty, and should succeed otherwise.
*/

#include "stdafx.h"
#include "12_6.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_6()
{
  Str_c name = "Geert";

  if (name)
    cout << "Hello " << name << "!" << endl;

  Str_c nickname;

  if (nickname)
    cout << "Hello " << nickname << "!" << endl;

  return 0;
}