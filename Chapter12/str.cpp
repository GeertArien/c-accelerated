#include "stdafx.h"
#include "str.h"

#include <iostream>
using std::ostream;
using std::istream;

ostream& operator<<(ostream& os, const Str& s)
{
  for (Str::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
}

istream& operator >> (istream& is, Str& s)
{
  // obliterate existing value(s)
  s.data.clear();
  // read and discard leading whitespace
  char c;
  while (is.get(c) && isspace(c))
    ; // nothing to do, except testing the condition
      // if still something to read, do so until next whitespace character
  if (is) {
    do s.data.push_back(c); // compile error!, data is private
    while (is.get(c) && !isspace(c));
    // if we read whitespace, then put it back on the stream
    if (is)
      is.unget();
  }
  return is;
}

Str operator+(const Str& s, const Str& t) {
  Str r = s;
  r += t;
  return r;
}