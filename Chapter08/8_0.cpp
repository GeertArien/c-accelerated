/**
Accelerated C++, Exercise 8-0, 8_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "8_0.h"

#include <string>
using std::string;
using std::getline;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::copy;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

#include "vec.h"
#include "words.h"

int test_split()
{
  cout << "Enter lines to split: " << endl;
  string s;
  while (getline(cin, s))
    split(s, ostream_iterator<string>(cout, "\n"));
  return 0;
}

void test_stream_iterators()
{
  cout << "Enter a few integers: ";

  vector<int> v;
  copy(istream_iterator<int>(cin), istream_iterator<int>(),
    back_inserter(v));  cout << endl;

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void test_median()
{
  vector<double> v_double = { 12.5, 16.3, 25.7 };
  cout << median(v_double) << endl;

  vector<int> v_int = { 12, 25, 16, 30 };
  cout << median(v_int) << endl;
}

int ex8_0()
{
  test_median();
  test_stream_iterators();
  cin.clear();
  test_split();
  return 0;
}
