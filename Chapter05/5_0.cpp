/**
Accelerated C++, Exercise 5-0, 5_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "words.h"

int test_string_split()
{
  string s;

  while (getline(cin, s))
  {
    vector<string> v = split(s);

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
      cout << v[i] << endl;
  }

  return 0;
}

int test_input_split() 
{
  string s;

  while (cin >> s)
    cout << s << endl;

  return 0;
}

int test_frame()
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<string> vert = vcat(frame(v1), frame(v2));

  vector<string>::const_iterator iter = vert.begin();

  while (iter != vert.end())
    cout << *iter++ << endl;

  vector<string> horz = hcat(frame(v1), frame(v2));

  iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;

  return 0;
}