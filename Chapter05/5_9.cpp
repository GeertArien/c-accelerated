/**
Accelerated C++, Exercise 5-9, 5_9.cpp

Write a program to write the lowercase words in the input followed by the
uppercase words.
*/

#include "stdafx.h"

#include "5_9.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::sort;

#include <functional>
using std::greater;

ostream& write_lower_upper(ostream& os, const vector<string>& v) 
{
  vector<string> v_copy = v;
  sort(v_copy.begin(), v_copy.end(), greater<string>());

  for (vector<string>::size_type i = 0; i < v_copy.size(); i++)
  {
    os << v_copy[i] << endl;
  }

  return os;
}

int ex5_9()
{
  vector<string> words = { "TEST" , "test" , "mountain", "BIKE", "six", "seven", "EIGHT", "NINE", "ten" };
  write_lower_upper(cout, words);
  
  return 0;
}