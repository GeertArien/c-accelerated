/**
Accelerated C++, Exercise 10-4, 10_4.cpp

Write a class that implements a list that holds strings.
*/

#include "stdafx.h"
#include "10_4.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::copy;

#include <iterator>
using stdext::checked_array_iterator;

String_list::String_list(const String_list& src) {
  *this = src;
  l = new string[max];

  for (string::size_type i = 0; i < size; i++)
    l[i] = src.l[i];
}

String_list::~String_list()
{
  delete[] l;
}

void String_list::resize()
{
  max *= 2;

  string* copy = new string[max];

  for (string::size_type i = 0; i < size; i++)
    copy[i] = l[i];

  delete[] l;

  l = copy;
}

void String_list::push_back(string str)
{
  if (size == max)
    resize();

  l[size++] = str;
}

int ex10_4()
{
  String_list str_list;

  str_list.push_back("test");
  str_list.push_back("more");
  str_list.push_back("testing");
  str_list.push_back("even more");
  str_list.push_back("yup");

  String_list::iterator iter = str_list.begin();

  while (iter != str_list.end())
    cout << *iter++ << endl;

  return 0;
}