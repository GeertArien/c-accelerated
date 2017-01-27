/**
Accelerated C++, Exercise 6-1, 6_1.cpp

Reimplement the frame and hcat operations from §5.8.1/93 and §5.8.3/94 to
use iterators.
*/

#include "stdafx.h"

#include "6_1.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::max;

#include <iostream>
using std::cout;
using std::endl;

string::size_type width(const vector<string>& v) 
{
  string::size_type maxlen = 0;
  typedef vector<string>::const_iterator iter;
  iter it = v.begin();

  while (it != v.end())
    maxlen = max(maxlen, it++->size());

  return maxlen;
}

vector<string> frame(const vector<string>& v)
{
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');
  vector<string>::const_iterator iter = v.begin();

  ret.push_back(border);

  while (iter != v.end()) 
  {
    ret.push_back("* " + *iter++ + string(maxlen - iter->size(), ' ') + " *");
  }

  ret.push_back(border);
  return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) 
{
  typedef vector<string>::const_iterator iter;
  iter iter_l = left.begin();
  iter iter_r = right.begin();
  vector<string> ret;

  string::size_type width1 = width(left) + 1;

  while (iter_l != left.end() || iter_r != right.end()) 
  {
    string s;

    if (iter_l != left.end())
      s = *iter_l++;

    s += string(width1 - s.size(), ' ');

    if (iter_r != right.end())
      s += *iter_r++;

    ret.push_back(s);
  }

  return ret;
}

int ex6_1() 
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<string> horz = hcat(frame(v1), frame(v2));
  vector<string>::iterator iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;

  return 0;
}