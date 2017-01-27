/**
Accelerated C++, Exercise 7-8, 7_8.cpp

Change the cross-reference program to find all the URLs in a file, and write all the
lines on which each distinct URL occurs.
*/

#include "stdafx.h"

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <iterator>
using std::distance;

#include <algorithm>
using std::unique;

#include "words.h"
#include "7_3.h"
#include "7_8.h"

int print_xref_urls(string file, size_t line_length)
{
  ifstream infile;
  infile.open(file);

  map<string, vector<int> > ret = xref_unique(infile, find_urls);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
  {
    string line = it->second.size() > 1 ? "lines" : "line";
    string s = it->first + " occurs on " + line + ": ";
    string s_spaces(s.size(), ' ');

    vector<int>::const_iterator line_it = it->second.begin();

    while (line_it != it->second.end())
    {
      string nr = to_string(*line_it);

      if (line_it != it->second.end() - 1)
        nr += ", ";

      if (s.size() + nr.size() > line_length)
      {
        cout << s << endl;
        s = s_spaces + nr;
      }
      else
        s += nr;

      ++line_it;
    }

    if (s.size() > s_spaces.size())
      cout << s << endl;

    cout << endl;
  }

  return 0;
}

int ex7_8()
{
  return print_xref_urls("urls.txt", 60);
}