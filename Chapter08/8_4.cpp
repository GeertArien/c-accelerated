/**
Accelerated C++, Exercise 8-4, 8_4.cpp

Implement the swap function that we used in §8.2.5/148. Why did we call swap
rather than exchange the values of *beg and *end directly? Hint: Try it and see.
*/

#include "stdafx.h"
#include "8_4.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <exception>
using std::domain_error;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::cout;
using std::endl;

template <class In>
string print_vector(In b, In e)
{
  if (b == e)
    throw domain_error("Empty range");

  stringstream ss;

  ss << "[ " << *b++;

  while (b != e)
    ss << ", " << *b++;

  ss << " ]";

  return ss.str();
}

int ex8_4()
{
  vector<int> vec = { 10, 15, 30, 105, 45, 70 };

  cout << "Reverse vector " << print_vector(vec.begin(), vec.end()) << " => ";
  reversing(vec.begin(), vec.end());
  cout << print_vector(vec.begin(), vec.end()) << endl;

  return 0;
}