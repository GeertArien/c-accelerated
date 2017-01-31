/**
Accelerated C++, Exercise 5-1, 5_1.cpp

Design and implement a program to produce a permuted index. A permuted index
is one in which each phrase is indexed by every word in the phrase. So, given the
following input,

The quick brown fox
jumped over the fence

the output would be

The quick       brown fox
jumped over the fence
The quick brown fox
jumped over the fence
jumped          over the fence
The             quick brown fox
jumped over     the fence
The quick brown fox
*/

#include "stdafx.h"

#include <algorithm>
using std::sort;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "words.h"

vector<string> rotate(const string& s) 
{
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  while (i != s.size()) 
  {
    while (i != s.size() && isspace(s[i]))
      ++i;

    string_size j = i;

    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j) 
    {
      string line = s.substr(i, s.size() - i);
      line += '\t';
      line += s.substr(0, i);
      ret.push_back(line);
      i = j;
    }
  }
  return ret;
}

void unrotate(vector<string>& v) 
{
  vector<string> v1, v2;
  vector<string>::iterator iter = v.begin();

  typedef string::size_type s_size;

  while (iter != v.end()) 
  {
    s_size seperator = iter->find('\t');

    v1.push_back(iter->substr(seperator + 1, iter->size() - 1));
    v2.push_back(iter->substr(0, seperator));
    ++iter;
  }

  iter = v.begin();
  vector<string>::iterator iter_v1 = v1.begin();
  vector<string>::iterator iter_v2 = v2.begin();
  s_size maxlen = width(v1);

  while (iter != v.end())
  {
    *iter = string(maxlen - iter_v1->size(), ' ') + *iter_v1 + '\t' + *iter_v2;
    ++iter, ++iter_v1, ++iter_v2;
  }
}

vector<string> permuted_index(const vector<string>& v) 
{
  vector<string>::const_iterator iter = v.begin();
  vector<string> permuted_v;

  while (iter != v.end())
  {
    vector<string> rotated_v = rotate(*iter++);
    permuted_v.insert(permuted_v.end(), rotated_v.begin(), rotated_v.end());
  }

  sort(permuted_v.begin(), permuted_v.end(), compare_ignore_case);

  unrotate(permuted_v);

  return permuted_v;
}

int ex5_1() 
{
  vector<string> v = { "The quick brown fox", "jumped over the fence" };
  vector<string> permuted_v = permuted_index(v);

  vector<string>::const_iterator iter = permuted_v.begin();

  while (iter != permuted_v.end())
    cout << *iter++ << endl;

  return 0;
}