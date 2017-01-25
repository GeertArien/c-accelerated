/**
Accelerated C++, Exercise 7-4, 7_4.cpp

The output produced by the cross-reference program will be ungainly if the input
file is large. Rewrite the program to break up the output if the lines get too long.
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
#include "7_4.h"

int print_formatted_xref(string file, size_t line_length)
{
  ifstream infile;
  infile.open(file);

  map<string, vector<int> > ret = xref_unique(infile);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
  {
    string s = it->first + " occurs on line(s): ";
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

int ex7_4()
{
  return print_formatted_xref("lines.txt", 60);
}
