/**
Accelerated C++, Exercise 2-8, 2_8.cpp

Write a program to generate the product of the numbers in the range [1, 10) .
*/

#include "stdafx.h"
#include "2_8.h"

#include <iostream>
using std::cout;
using std::endl;

int ex2_8() 
{  
  int product = 1;

  for (int i = product + 1; i < 10; i++)
    product *= i;

  cout << product << endl;

  return 0;
}