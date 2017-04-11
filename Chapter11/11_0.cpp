/**
Accelerated C++, Exercise 11-0, 11_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "11_0.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include "vec.h"

template<class T>
ostream& print_vec(const Vec<T> v, ostream& os)
{
  if (v.size() > 0)
  {
    os << v[0];

    for (Vec<T>::size_type i = 1; i < v.size(); i++)
      os << ", " << v[i];

    os << endl;
  }

  return os;
}

int ex11_0()
{
  Vec<int> v1(5, 5);
  Vec<int> v2;

  v2 = v1;

  for (Vec<int>::size_type i = 2; i < v1.size(); i++)
    v1[i] = 7;

  for (Vec<int>::size_type i = 0; i < 10; i++)
    v2.push_back(10);

  print_vec(v1, cout);
  print_vec(v2, cout);

  return 0;
}