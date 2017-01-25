/**
Accelerated C++, Exercise 7-1, 7_1.cpp

Extend the program from §7.2/124 to produce its output sorted by occurrence
count. That is, the output should group all the words that occur once, followed by those
that occur twice, and so on.
*/

#include "stdafx.h"

#include "7_1.h"

#include <iostream>
using std::cin;     using std::cout;
using std::istream; using std::ostream;
using std::endl;

#include <string>
using std::string;

#include <map>
using std::map;     using std::multimap;

#include <algorithm>
using std::transform;

#include <iterator>
using std::inserter;

#include "words.h"

istream& count_sort_words(istream& is, ostream& os)
{
  string s;
  map<string, int> counters;

  while (is >> s)
    ++counters[s];

  multimap<int, string> counters_r;
  transform(counters.begin(), counters.end(), inserter(counters_r, counters_r.begin()), flip_count_pair);

  for (multimap<int, string>::const_iterator it = counters_r.begin(); it != counters_r.end(); ++it)
    os << it->second << "\t" << it->first << endl;

  return is;
}

int ex7_1() {

  if (count_sort_words(cin, cout))
    return 0;
  else
    return 1;
}