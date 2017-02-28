/**
Accelerated C++, Exercise 3-3, 3_3.cpp

Write a program to count how many times each distinct word appears in its input.
*/

#include "stdafx.h"
#include "3_3.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>
using std::sort;

vector<string> GetInput()
{
  string word;
  vector<string> words;

  cout << "Please enter some words:" << endl;

  while (cin >> word)
  {
    words.push_back(word);
  }

  return words;
}


int CountDistinctWord(vector<string> words) 
{

  if (words.size() < 2) 
  {
    cout << "Please enter atleast 2 words." << endl;
    return 1;
  }

  sort(words.begin(), words.end());

  for (vector<string>::size_type i = 0, counter = 0; i < words.size(); i++) 
  {
    counter++;
    if (i + 1 == words.size() || words[i] != words[i + 1]) 
    {
      cout << words[i] << ": " << counter << endl;
      counter = 0;
    }
  }

  return 0;
}

int ex3_3()
{
  return CountDistinctWord(GetInput());
}