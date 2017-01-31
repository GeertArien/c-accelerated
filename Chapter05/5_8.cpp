/**
Accelerated C++, Exercise 5-8, 5_8.cpp

In the hcat function from §5.8.3/95, what would happen if we defined s outside
the scope of the while? Rewrite and execute the program to confirm your hypothesis.
*/

#include "stdafx.h"

#include "5_8.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "words.h"

vector<string> hcat_alternative(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;

  string::size_type width1 = width(left) + 1;

  vector<string>::size_type i = 0, j = 0;

  string s;

  while (i != left.size() || j != right.size()) 
  {
    if (i != left.size())
      s = left[i++];

    s += string(width1 - s.size(), ' ');

    if (j != right.size())
      s += right[j++];

    ret.push_back(s);
  }

  return ret;
}

int ex5_8() 
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<string> horz = hcat_alternative(v1, v2);

  vector<string>::const_iterator iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;

  return 0;
}