/**
Accelerated C++, Exercise 10-4, 10_4.cpp

Write a class that implements a list that holds strings.
*/

#include "stdafx.h"
#include "10_4.h"

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::copy;

#include <iterator>
using stdext::checked_array_iterator;

String_list::~String_list()
{
  for (size_t i = 0; i < size; i++)
    delete l[i];

  delete l;
}

void String_list::resize()
{
  max *= 2;

  char** copy = new char*[max];

  for (size_t i = 0; i < size; i++)
  {
    copy[i] = l[i];
  }

  delete l;

  l = copy;
}

void String_list::push_back(const char* str)
{
  if (size == max)
    resize();

  size_t length = strlen(str) + 1;
  char* new_str = new char[length];
  copy(str, str + length, checked_array_iterator<char*>(new_str, length));

  l[size++] = new_str;
}

int ex10_4()
{
  String_list str_list;

  str_list.push_back("test");
  str_list.push_back("more");
  str_list.push_back("testing");
  str_list.push_back("even more");
  str_list.push_back("yup");

  char** iter = str_list.begin();

  while (iter != str_list.end())
    cout << *iter++ << endl;

  return 0;
}