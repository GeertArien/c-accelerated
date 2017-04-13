/**
Accelerated C++, Exercise 11-8, 11_8.cpp

Write a simplified version of the standard list class and its associated iterator.
*/

#include "stdafx.h"
#include "11_8.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>

int ex11_8()
{
  LList<int> list;
  list.push_back(5);
  list.push_back(10);
  list.push_back(15);

  LList<int>::iterator iter = list.begin();

  while (iter != list.end())
    cout << *iter++ << endl;

  return 0;
}