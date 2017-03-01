/**
Accelerated C++, Exercise 7-0, 7_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "7_0.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;

#include "words.h"

int test_xref() 
{
  map<string, vector<int> > ret = xref(cin);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) 
  {
    cout << it->first << " occurs on line(s): ";

    vector<int>::const_iterator line_it = it->second.begin();
    cout << *line_it;

    ++line_it;

    while (line_it != it->second.end())
    {
      cout << ", " << *line_it;
      ++line_it;
    }

    cout << endl;
  }

  return 0;
}

int test_generate_sentence() 
{
  vector<string> sentence = gen_sentence(read_grammar(cin));
  vector<string>::const_iterator it = sentence.begin();

  if (!sentence.empty()) 
  {
    cout << *it;
    ++it;
  }

  while (it != sentence.end())
  {
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;
}

int ex7_0() 
{
  test_xref();
  cin.clear();
  test_generate_sentence();
  return 0;
}