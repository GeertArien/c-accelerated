/**
Accelerated C++, Exercise 4-2, 4_2.cpp

Write a program to calculate the squares of int values up to 100. The program
should write two columns: The first lists the value; the second contains the square of
that value. Use setw (described above) to manage the output so that the values line up
in columns.
*/

#include "stdafx.h"
#include "4_2.h"

#include <vector>
using std::vector;

#include <exception>
using std::domain_error;

#include <iostream>
using std::ostream;
using std::streamsize;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

vector<int> square(const unsigned int range) 
{
  vector<int> squares;
  if (range > squares.max_size())
    throw domain_error("Range argument exceeds vector limit.");

  for (unsigned int i = 0; i < range; i++)
    squares.push_back(i * i);

  return squares;
}

unsigned GetNumberOfDigits(unsigned i)
{
  return i > 0 ? (int)log10((double)i) + 1 : 1;
}

ostream& print_squares(ostream& os, const vector<int>& v) 
{
  if (os)
  {
    for (vector<int>::size_type i = 0; i < v.size(); i++)
    {
      streamsize s_size = os.width();
      os << setw(2) << i << " " << setw(4) << v[i] << endl;
      os.width(s_size);
    }
  }

  return os;
}

int ex4_2()
{
  vector<int> v = square(100);
  print_squares(cout, v);

  return 0;
}