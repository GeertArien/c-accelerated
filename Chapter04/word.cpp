#include "stdafx.h"
#include "word.h"
#include <algorithm>

using std::string;  using std::istream;
using std::ostream; using std::vector;
using std::endl;    using std::domain_error;

istream & read(istream& is, vector<string>& v) {
  if (is) {
    is.clear();

    string s;
    while (is >> s)
      v.push_back(s);

    is.clear();
  }

  return is;
}

unsigned count_distinct(vector<string> words) {
  if (words.size() < 2)
    return words.size();

  sort(words.begin(), words.end());

  unsigned count = 1;

  for (vector<string>::size_type i = 1; i < words.size(); i++) {
    if (words[i] != words[i - 1])
      count++;
  }

  return count;
}

ostream& count_occurence(ostream& os, vector<string> words) {
  if (words.size() < 2) {
    throw domain_error("Vector should have atleast two elements.");
  }

  sort(words.begin(), words.end());

  for (vector<string>::size_type i = 0, counter = 0; i < words.size(); i++) {
    counter++;
    if (i + 1 == words.size() || words[i] != words[i + 1]) {
      os << words[i] << ": " << counter << endl;
      counter = 0;
    }
  }

  return os;
}
