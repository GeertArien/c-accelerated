/**
Accelerated C++, Exercise 12_14, 12_14.cpp

Write a program to initialize a Vec from a string.
*/

#include "stdafx.h"
#include "12_14.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "vec.h"

int ex12_14()
{
  string s = "A lonesome string.";

  Vec<char> v(s.begin(), s.end());

  for (size_t i = 0; i < v.size(); i++)
    cout << v[i];

  cout << endl;

  return 0;
}