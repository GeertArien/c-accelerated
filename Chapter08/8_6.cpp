/**
Accelerated C++, Exercise 8-6, 8_6.cpp

Suppose that m has type map<int, string> , and that we encounter a call to
copy(m.begin(), m.end(), back_inserter(x)) . What can we say about the
type of x ? What if the call were copy(x.begin(), x.end(), back_inserter(m))
instead?
*/

#include "stdafx.h"
#include "8_6.h"

#include <map>
using std::map;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iterator>
using std::back_inserter;

#include <algorithm>
using std::copy;

#include <utility>
using std::pair;

int ex8_6()
{
  map<int, string> m = { { 1, "hello" },{ 3, "bye" } };

  vector<pair<int, string>> x = { { 1, "thanks" },{ 3, "yo" } };

  // container that supports output iterator operations, push_back and that holds <int,string> pairs
  copy(m.begin(), m.end(), back_inserter(x));

  // map doesn't support push_back so back_inserter is an invalid operation
  //copy(x.begin(), x.end(), back_inserter(m));

  return 0;
}