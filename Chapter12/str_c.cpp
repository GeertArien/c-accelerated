#include "stdafx.h"
#include "str_c.h"

#include <iostream>
using std::ostream;
using std::istream;

#include <iterator>
using std::ostream_iterator;

#include <algorithm>
using std::copy;

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

void Str_c::prepend(const char *str, const size_t count)
{
  size_t old_length = size();

  char *copy = new char[old_length];
  memcpy(copy, d, old_length);
  uncreate();

  length = old_length + count + 1;
  d = new char[length];
  memcpy(d, str, count);
  memcpy(&d[count], copy, old_length);
  d[length - 1] = '\0';

  delete[] copy;
}

void Str_c::append(const char c)
{
  append(&c, 1);
}

Str_c operator+(const Str_c& s, const Str_c& t) 
{
  Str_c r = s;
  r += t;
  return r;
}

Str_c operator+(const Str_c& s, const char* str)
{
  Str_c r = s;
  r += str;
  return r;
}

Str_c operator+(const char* str, const Str_c& s)
{
  Str_c r = s;
  r.prepend(str, strlen(str));
  return r;
}

ostream& operator<<(ostream& os, const Str_c& s)
{
  copy(s.begin(), s.end(), ostream_iterator<char>(os));
  return os;
}

istream& operator>>(istream& is, Str_c& s)
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
    do s.append(c);
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

istream& getline(istream& is, Str_c& s)
{
  // obliterate existing value(s)
  s.uncreate();
  s.create(0, '\0');

  char c;

  if (is) {
    while (is.get(c) && c != '\n')
      s.append(c); 
  }

  return is;
}