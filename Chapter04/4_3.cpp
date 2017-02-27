/**
Accelerated C++, Exercise 4-3, 4_3.cpp

What happens if we rewrite the previous program to allow values up to but not
including 1000 but neglect to change the arguments to setw? Rewrite the program to
be more robust in the face of changes that allow i to grow without adjusting the setw
arguments.
*/

#include "stdafx.h"
#include "4_3.h"
#include "4_2.h"

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;
using std::streamsize;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

ostream& print_squares_robust(ostream& os, const vector<int>& v)
{
  if (os)
  {
    unsigned digits_i = GetNumberOfDigits(v.size());
    unsigned digits_v = GetNumberOfDigits(v.back());

    for (vector<int>::size_type i = 0; i < v.size(); i++)
    {
      streamsize s_size = os.width();
      os << setw(digits_i) << i << " " << setw(digits_v) << v[i] << endl;
      os.width(s_size);
    }
  }

  return os;
}

int ex4_3()
{
  vector<int> v = square(1000);
  print_squares_robust(cout, v);

  return 0;
}