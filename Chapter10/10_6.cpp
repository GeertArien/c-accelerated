/**
Accelerated C++, Exercise 10-6, 10_6.cpp

Test the class by rewriting the split function to put its output into a
String_list.
*/

#include "stdafx.h"
#include "10_6.h"

#include <string>
using std::string;

#include <algorithm>
using std::find_if;

#include <iostream>
using std::cout;
using std::endl;

#include "10_4.h"

bool space(char c)
{
  return isspace(c) != 0;
}

bool not_space(char c)
{
  return !isspace(c);
}

String_list split(const string& str)
{
  typedef string::const_iterator iter;
  String_list ret;

  iter i = str.begin();
  while (i != str.end())
  {

    i = find_if(i, str.end(), not_space);

    iter j = find_if(i, str.end(), space);

    if (i != str.end())
      ret.push_back(string(i, j));
    i = j;
  }
  return ret;
}

int ex10_6()
{
  string str = "Please split this amazing string!";
  String_list str_l = split(str);
  String_list::iterator iter = str_l.begin();

  while (iter != str_l.end())
    cout << *iter++ << endl;

  return 0;
}