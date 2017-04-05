/**
Accelerated C++, Exercise 10-3, 10_3.cpp

Write a test program to verify that the median function operates correctly.
Ensure that calling median does not change the order of the elements in the container.
*/

#include "stdafx.h"
#include "10_3.h"

#include "10_2.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template<class T>
ostream& print_vector(const vector<T> v, ostream& os)
{
  if (v.size() > 0)
  {
    os << v[0];

    for (vector<T>::size_type i = 1; i < v.size(); i++)
      os << ", " << v[i];

    os << endl;
  }

  return os;
}

int ex10_3()
{
  vector<double> v_double = { 12.5, 5.25, 25.7, 16.3, 1.26 };

  print_vector(v_double, cout);

  cout << median<double, vector<double>::iterator>(v_double.begin(), v_double.end()) << endl;

  print_vector(v_double, cout);

  return 0;
}