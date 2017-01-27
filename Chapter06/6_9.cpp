/**
Accelerated C++, Exercise 6-9, 6_9.cpp

Use a library algorithm to concatenate all the elements of a vector<string>.
*/

#include "stdafx.h"

#include "6_9.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <numeric>
using std::accumulate;

string concat(const vector<string>& v) 
{
  string s;
  return accumulate(v.begin(), v.end(), s);
}

int ex6_9() 
{
  vector<string> v = { "one direction", "mama mia", "mamo testo", "lake district mall" };
  cout << concat(v) << endl;

  return 0;
}