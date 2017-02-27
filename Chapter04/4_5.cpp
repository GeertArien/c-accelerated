/**
Accelerated C++, Exercise 4-5, 4_5.cpp

Write a function that reads words from an input stream and stores them in a
vector. Use that function both to write programs that count the number of words in
the input, and to count how many times each word occurred.
*/

#include "stdafx.h"
#include "4_5.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;

#include <exception>
using std::domain_error;

istream & read(istream& is, vector<string>& v) 
{
  if (is) 
  {
    is.clear();

    string s;
    while (is >> s)
      v.push_back(s);

    is.clear();
  }

  return is;
}

unsigned count_distinct(vector<string> words) 
{
  if (words.size() < 2)
    return words.size();

  sort(words.begin(), words.end());

  unsigned count = 1;

  for (vector<string>::size_type i = 1; i < words.size(); i++) 
  {
    if (words[i] != words[i - 1])
      count++;
  }

  return count;
}

ostream& count_occurence(ostream& os, vector<string> words) 
{
  if (words.size() < 2) 
  {
    throw domain_error("Vector should have atleast two elements.");
  }

  sort(words.begin(), words.end());

  for (vector<string>::size_type i = 0, counter = 0; i < words.size(); i++) 
  {
    counter++;
    if (i + 1 == words.size() || words[i] != words[i + 1]) 
    {
      os << words[i] << ": " << counter << endl;
      counter = 0;
    }
  }

  return os;
}

int ex4_5()
{
  vector<string> words;
  read(cin, words);
  cout << "Number of distinct words: " << count_distinct(words) << endl;
  count_occurence(cout, words);

  return 0;
}