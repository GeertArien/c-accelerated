/**
Accelerated C++, Exercise 7-7, 7_7.cpp

Change the driver for the cross-reference program so that it writes line if there is
only one line and lines otherwise.
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
#include "7_7.h"

int print_formatted_line_xref(string file, size_t line_length)
{
  ifstream infile;
  infile.open(file);

  map<string, vector<int> > ret = xref_unique(infile);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
  {
    string line = it->second.size() > 1 ? "lines" : "line";
    string s = it->first + " occurs on "+ line + ": ";
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

int ex7_7()
{
  return print_formatted_line_xref("lines.txt", 60);
}