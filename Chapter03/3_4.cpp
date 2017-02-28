/**
Accelerated C++, Exercise 3-4, 3_4.cpp

Write a program to report the length of the longest and shortest string in its
input.
*/

#include "stdafx.h"
#include "3_4.h"
#include "3_3.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int LongestShortestString(vector<string> words) 
{

  if (words.size() < 1) 
  {
    cout << "Please enter atleast 1 words." << endl;
    return 1;
  }

  vector<string>::size_type shortest, longest;
  shortest = longest = words[0].size();

  for (vector<string>::size_type i = 1; i < words.size(); i++)
  {
    if (words[i].size() < shortest)
      shortest = words[i].size();
    if (words[i].size() > longest)
      longest = words[i].size();
  }

  cout << "The shortest word is " << shortest << " characters long." << endl
    << "The longest word is " << longest << " characters long." << endl;

  return 0;
}

int ex3_4()
{
  return LongestShortestString(GetInput());
}