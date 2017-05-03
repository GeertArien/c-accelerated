/**
Accelerated C++, Exercise 11-8, 11_8.cpp

Write a simplified version of the standard list class and its associated iterator.
*/

#include "stdafx.h"
#include "11_8.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int ex11_8()
{
  LList<int> list;
  list.push_back(5);
  list.push_back(10);
  list.push_back(15);

  LList<int>::iterator iter = list.begin();

  cout << *++iter << endl;
  cout << *--iter << endl;

  while (iter != list.end())
    cout << *iter++ << endl;

  LList<string> stringlist(5, "test");
  LList<string> stringlist_copy = stringlist;
  LList<string>::iterator listIter = stringlist.begin();

  *listIter = "first";

  while (listIter != stringlist.end())
    cout << *listIter++ << endl;

  if (stringlist_copy.size() > 0) {
    listIter = stringlist_copy.begin();
    while (listIter != stringlist.end())
      cout << *listIter++ << endl;
  }

  return 0;
}