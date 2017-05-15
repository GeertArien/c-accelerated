#include "stdafx.h"
#include "str_c.h"

#include <iostream>
using std::ostream;
using std::istream;

void Str_c::create(size_t s, char c)
{
  d = new char[s + 1];
  length = s + 1;
  memset(d, c, s);
  d[s] = '\0';
}

Str_c& Str_c::operator=(const Str_c& rhs)
{
  // check for self-assignment
  if (&rhs != this) {
    // free the array in the left-hand side
    uncreate();
    // copy elements from the right-hand to the left-hand side
    create(rhs.d, rhs.d + rhs.size());
  }
  return *this;
}

void Str_c::append(const Str_c& s)
{
  append(s.data(), s.size());
}

void Str_c::append(const char *str, const size_t count)
{
  size_t old_length = size();

  char *copy = new char[old_length];
  memcpy(copy, d, old_length);
  uncreate();

  length = old_length + count + 1;
  d = new char[length];
  memcpy(d, copy, old_length);
  memcpy(&d[old_length], str, count);
  d[length - 1] = '\0';

  delete[] copy;
}

void Str_c::append(const char c)
{
  append(&c, 1);
}

Str_c operator+(const Str_c& s, const Str_c& t) {
  Str_c r = s;
  r += t;
  return r;
}

ostream& operator<<(ostream& os, const Str_c& s)
{
  for (Str_c::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
}

istream& operator >> (istream& is, Str_c& s)
{
  // obliterate existing value(s)
  s.uncreate();
  s.create(0, '\0');
  // read and discard leading whitespace
  char c;
  while (is.get(c) && isspace(c))
    ; // nothing to do, except testing the condition
      // if still something to read, do so until next whitespace character
  if (is) {
    do s.append(c); // compile error!, data is private
    while (is.get(c) && !isspace(c));
    // if we read whitespace, then put it back on the stream
    if (is)
      is.unget();
  }
  return is;
}

size_t Str_c::copy_characters(char* dest, size_t count) const
{
  size_t i;

  for (i = 0; i < count && i < size(); i++)
    dest[i] = d[i];

  return i;
}