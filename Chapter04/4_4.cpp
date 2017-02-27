/**
Accelerated C++, Exercise 4-4, 4_4.cpp

Now change your squares program to use double values instead of ints. Use
manipulators to manage the output so that the values line up in columns.
*/

#include "stdafx.h"
#include "4_4.h"

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;
using std::streamsize;
using std::cout;
using std::endl;

#include <exception>
using std::domain_error;

#include <iomanip>
using std::setw;

vector<double> square_double(const unsigned int range) 
{
  vector<double> squares;
  if (range > squares.max_size())
    throw domain_error("Range argument exceeds vector limit.");

  for (unsigned int i = 0; i < range; i++)
    squares.push_back(i * i);

  return squares;
}

double GetNumberOfDigits(const double i)
{
  return i > 0 ? log10(i) + 1 : 1;
}

ostream& print_squares(ostream& os, const vector<double>& v)
{
  if (os)
  {
    streamsize digits_i = (streamsize) GetNumberOfDigits(v.size());
    streamsize digits_v = (streamsize) GetNumberOfDigits(v.back());

    for (vector<double>::size_type i = 0; i < v.size(); i++) 
    {
      streamsize s_size = os.width();
      os << setw(digits_i) << i << " " << setw(digits_v) << v[i] << endl;
      os.width(s_size);
    }
  }

  return os;
}

int ex4_4()
{
  vector<double> v = square_double(500);
  print_squares(cout, v);

  return 0;
}