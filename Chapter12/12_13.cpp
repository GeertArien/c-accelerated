/**
Accelerated C++, Exercise 12_13, 12_13.cpp

Provide an assign function that could be used to assign the values in an array
to a Vec.
*/

#include "stdafx.h"
#include "12_13.h"

#include <iostream>
using std::cout;
using std::endl;

#include "vec.h"

int ex12_13()
{
  Vec<char> v;

  char data[] = { 'h', 'e', 'l', 'l', 'o' };
  v.assign(data, data + sizeof(data));

  for (size_t i = 0; i < v.size(); i++)
    cout << v[i];

  cout << endl;

  return 0;
}