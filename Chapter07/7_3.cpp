/**
Accelerated C++, Exercise 7-3, 7_3.cpp

The cross-reference program from §7.3/126 could be improved: As it stands, if a
word occurs more than once on the same input line, the program will report that line
multiple times. Change the code so that it detects multiple occurrences of the same line
number and inserts the line number only once.
*/

#include "stdafx.h"

#include "7_3.h"

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

map<string, vector<int> > xref_unique(istream& in, vector<string> find_words(const string&)) 
{
  string line;
  int line_number = 0;
  map<string, vector<int> > ret;

  while (getline(in, line)) 
  {
    ++line_number;

    vector<string> words = find_words(line);

    for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
      ret[*it].push_back(line_number);
  }

  for (map<string, vector<int> >::iterator it = ret.begin(); it != ret.end(); ++it)
    it->second.resize(distance(it->second.begin(), unique(it->second.begin(), it->second.end())));

  return ret;
}

int print_xref(string file) 
{
  ifstream infile;
  infile.open(file);

  map<string, vector<int> > ret = xref_unique(infile);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
  {
    cout << it->first + " occurs on line(s): ";

    vector<int>::const_iterator line_it = it->second.begin();

    cout << *line_it++;

    while (line_it != it->second.end())
      cout << ", " << *line_it++;

    cout << endl;
  }

  return 0;
}

int ex7_3()
{
  return print_xref("lines.txt");
}
