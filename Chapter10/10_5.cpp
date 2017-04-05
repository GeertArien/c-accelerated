/**
Accelerated C++, Exercise 10-5, 10_5.cpp

Write a bidirectional iterator for your String_list class.
*/

#include "stdafx.h"
#include "10_5.h"

#include "10_4.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int ex10_5()
{
  String_list str_list;

  str_list.push_back("one");
  str_list.push_back("two");
  str_list.push_back("three");
  str_list.push_back("four");
  str_list.push_back("five");

  String_list::iterator iter = str_list.begin();

  while (iter != str_list.end())
  {
    cout << *iter << endl;
    *iter++ = "reverse";
  }

  while (iter != str_list.begin())
    cout << *(--iter) << endl;

  return 0;
}