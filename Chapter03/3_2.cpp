/**
Accelerated C++, Exercise 3-2, 3_2.cpp

Write a program to compute and print the quartiles (that is, the quarter of the
numbers with the largest values, the next highest quarter, and so on) of a set of
integers.
*/

#include "stdafx.h"
#include "3_2.h"

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::copy;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <iterator>

int quartiles(vector<int>& someInts)
{
  sort(someInts.begin(), someInts.end());

  int quarter = someInts.size() / 4;
  int remainder = someInts.size() % 4;

  if (quarter == 0) 
  {
    cout << "Vector is smaller than 4 elements." << endl;
    return 1;
  }

  int start = someInts.size();

  for (int i = 0; i < 4; i++, remainder--) 
  {
    stringstream result;
    int quarterSize = remainder > 0 ? quarter + 1 : quarter;
    int stop = start - quarterSize;
    vector<int>::const_iterator first = someInts.begin() + stop;
    vector<int>::const_iterator last = someInts.begin() + start;
    copy(first, last, std::ostream_iterator<int>(result, " "));
    cout << "Quarter " << std::to_string(i + 1) << ": " + result.str() << endl;
    start -= quarterSize;
  }

  return 0;
}

int ex3_2()
{
  vector<int> someInts = { 10, 12, 5, 8, 13, 25, 1, 121, 85, 99, 120, 180, 75, 205, 16, 22, 99, 16 };

  return quartiles(someInts);
}