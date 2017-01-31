/**
Accelerated C++, Exercise 5-11, 5_11.cpp

In text processing it is sometimes useful to know whether a word has any
ascenders or descenders. Ascenders are the parts of lowercase letters that extend above
the text line; in the English alphabet, the letters b, d, f, h, k, l, and t have ascenders.
Similarly, the descenders are the parts of lowercase letters that descend below the line;
In English, the letters g, j, p, q, and y have descenders. Write a program to determine
whether a word has any ascenders or descenders. Extend that program to find the
longest word in the dictionary that has neither ascenders nor descenders.
*/

#include "stdafx.h"

#include "5_11.h"

#include <string>
using std::string;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

bool has_asc_desc(const string& s) 
{
  string::const_iterator iter = s.begin();
  string asc_desc = "bdfhkltgjpqy";

  while (iter != s.end())
  {
    std::size_t found = asc_desc.find(tolower(*iter++));
    if (found != std::string::npos)
      return true;
  }

  return false;
}

list<string> extract_asc_desc(list<string>& l)
{
  list<string> l_ad;
  list<string>::const_iterator iter = l.begin();

  while (iter != l.end())
  {
    if (has_asc_desc(*iter))
    {
      l_ad.push_back(*iter);
      iter = l.erase(iter);
    }
    else
      ++iter;
  }
  return l_ad;
}

string longest_not_asc_desc(list<string> l)
{
  extract_asc_desc(l);
  string longest;

  for (list<string>::const_iterator iter = l.begin(); iter != l.end(); iter++)
    if (iter->length() > longest.length())
      longest = *iter;

  return longest;
}

int ex5_11() 
{
  list<string> words = { "TEST" , "teet" , "racecar", "BIKE", "six", "madam", "EIGHT", "reDder", "ten", "multilangual" };
  cout << longest_not_asc_desc(words) << endl;

  return 0;
}