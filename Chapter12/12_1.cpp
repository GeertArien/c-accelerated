/**
Accelerated C++, Exercise 12-1, 12_1.cpp

Reimplement the Str class, but choose an implementation strategy that requires
that the class manage the storage itself. For example, you might store an array of char
and a length. Consider what implications this change in design has for copy control. Also
consider the cost of using Vec, (e.g., in storage overhead).
*/

#include "stdafx.h"
#include "12_1.h"

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

void Str_c::create(size_t s, char c)
{
  data = new char[s];
  length = s;
  memset(data, c, s);
}

Str_c& Str_c::operator=(const Str_c& rhs)
{
  // check for self-assignment
  if (&rhs != this) {
    // free the array in the left-hand side
    uncreate();
    // copy elements from the right-hand to the left-hand side
    create(rhs.data, rhs.data + rhs.length);
  }
  return *this;
}

void Str_c::append(const Str_c& s)
{
  size_t old_length = length;

  char *copy = new char[old_length];
  memcpy(copy, data, old_length);
  uncreate();

  length = old_length + s.size();
  data = new char[length];
  memcpy(data, copy, old_length);
  memcpy(data + old_length, s.data, s.size());

  delete[] copy;
}

void Str_c::append(const char c)
{
  append(&c + '\0');
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

int ex12_1()
{
  Str_c s("hello"); // construct s
  Str_c t = "hello"; // initialize t
  s = "hello"; // assign a new value to s
  Str_c s1 = "test";
  Str_c s2 = "ing";

  cout << "Enter a string: ";
  cin >> s; // use the input operator to read a string
  cout << s << endl; // use the output operator to write a string
  s[3]; // use the index operator to access a character
  s1 + s2; // use the addition operator to concatenate two strings

  Str_c name = "Geert";
  Str_c greeting = "Hello, " + name + "!";

  Str_c temp1("Hello, "); // Str::Str(const char*)
  Str_c temp2 = temp1 + name; // operator*(const Str&, const Str&)
  Str_c temp3("!"); // Str::Str(const char*)
  greeting = temp2 + temp3; // operator*(const Str&, const Str&)

  return 0;
}