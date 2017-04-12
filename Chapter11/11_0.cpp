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

int ex11_0()
{
  Vec<int> v1(5, 5);
  Vec<int> v2;

  v2 = v1;

  for (Vec<int>::size_type i = 2; i < v1.size(); i++)
    v1[i] = 7;

  for (Vec<int>::size_type i = 0; i < 10; i++)
    v2.push_back(10);

  v1.print_vec(cout);
  v2.print_vec(cout);

  return 0;
}