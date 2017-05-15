/**
Accelerated C++, Exercise 12-1, 12_1.cpp

Reimplement the Str class, but choose an implementation strategy that requires
that the class manage the storage itself. For example, you might store an array of char
and a length. Consider what implications this change in design has for copy control. Also
consider the cost of using Vec, (e.g., in storage overhead).
*/

#include "stdafx.h"
#include "12_1.h"
#include "str_c.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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