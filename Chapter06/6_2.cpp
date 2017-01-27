/**
Accelerated C++, Exercise 6-2, 6_2.cpp

Write a program to test the find_urls function.
*/

#include "stdafx.h"

#include "6_2.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include "words.h"

int ex6_2() 
{
  string s = "http:// http://test.com toast.com ftp://fttpt :// ://google.be f://l";
  vector<string> v = find_urls(s);
  vector<string>::iterator iter = v.begin();

  while (iter != v.end())
    cout << *iter++ << endl;

  return 0;
}