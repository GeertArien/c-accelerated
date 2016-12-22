#include "stdafx.h"
#include "word.h"

using std::string;  using std::istream;
using std::ostream; using std::vector;

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

unsigned count_distinct(const vector<string>&) {

}

ostream& count_occurence(ostream&, const vector<string>&) {

}
