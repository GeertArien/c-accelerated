/**
Accelerated C++, Exercise 12-0, 12_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "12_0.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "str.h"

int ex12_0()
{
  Str s("hello"); // construct s
  Str t = "hello"; // initialize t
  s = "hello"; // assign a new value to s
  Str s1 = "test";
  Str s2 = "ing";

  cout << "Enter a string: ";
  cin >> s; // use the input operator to read a string
  cout << s << endl; // use the output operator to write a string
  s[3]; // use the index operator to access a character
  s1 + s2; // use the addition operator to concatenate two strings

  Str name = "Geert";
  Str greeting = "Hello, " + name + "!";

  Str temp1("Hello, "); // Str::Str(const char*)
  Str temp2 = temp1 + name; // operator*(const Str&, const Str&)
  Str temp3("!"); // Str::Str(const char*)
  greeting = temp2 + temp3; // operator*(const Str&, const Str&)

  return 0;
}