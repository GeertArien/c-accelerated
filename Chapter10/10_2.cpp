/**
Accelerated C++, Exercise 10-2, 10_2.cpp

Rewrite the median function from §8.1.1/140 so that we can call it with either a
vector or a built-in array. The function should allow containers of any arithmetic type.
*/

#include "stdafx.h"
#include "10_2.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::end;

#include <exception>
using std::domain_error;

#include <algorithm>
using std::sort;

template<class T, class In>
T median(In begin, In end)
{
  if (begin == end)
    throw domain_error("median of an empty container");

  vector<T> v;

  while (begin != end)
    v.push_back(*begin++);

  sort(v.begin(), v.end());

  vector<T>::size_type mid = v.size() / 2;
  return v.size() % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int ex10_2()
{
  double a_double[] = { 12.5, 16.3, 25.7 };
  vector<double> v_double(a_double, end(a_double));
  int a_int[] = { 12, 26, 16, 30 };
  vector<int> v_int(a_int, end(a_int));

  cout << median<double, double*>(a_double, end(a_double)) << endl;
  cout << median<double, vector<double>::iterator>(v_double.begin(), v_double.end()) << endl;
  cout << median<int, int*>(a_int, end(a_int)) << endl;
  cout << median<int, vector<int>::iterator>(v_int.begin(), v_int.end()) << endl;

  return 0;
}