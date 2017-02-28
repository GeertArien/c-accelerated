/**
Accelerated C++, Exercise 2-7, 2_7.cpp

Write a program to count down from 10 to -5 .
*/

#include "stdafx.h"
#include "2_7.h"

#include <iostream>
using std::cout;
using std::endl;

int ex2_7() 
{
  int x = 10;

  while (x >= -5)
  {
    cout << x-- << endl;
  }

  return 0;
}