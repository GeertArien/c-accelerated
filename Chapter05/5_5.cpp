/**
Accelerated C++, Exercise 5-5, 5_5.cpp

Write a function named center(const vector<string>&) that returns a
picture in which all the lines of the original picture are padded out to their full width, and
the padding is as evenly divided as possible between the left and right sides of the
picture. What are the properties of pictures for which such a function is useful? How can
you tell whether a given picture has those properties?
*/

#include "stdafx.h"

#include "5_5.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "words.h"

vector<string> center(const vector<string>& v) 
{
  vector<string> v_out;
  vector<string>::size_type maxlen = width(v);
  vector<string>::const_iterator iter = v.begin();

  while (iter != v.end()) 
  {
    int spaces_l = (maxlen - iter->size()) / 2;
    int spaces_r = maxlen - iter->size() - spaces_l;
    v_out.push_back(string(spaces_l, ' ') + *iter++ + string(spaces_r, ' '));
  }

  return v_out;
}

int ex5_5() 
{
  vector<string> v = { "This is really great", "really", "super awesome", "awesomesauce" };
  vector<string> centered_v = center(v);

  vector<string>::const_iterator iter = centered_v.begin();

  while (iter != centered_v.end())
    cout << *iter++ << endl;

  return 0;
}