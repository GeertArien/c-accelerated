/**
Accelerated C++, Exercise 10-0, 10_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "10_0.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;
using std::getline;

#include <algorithm>
using std::copy;

#include <iterator>
using stdext::checked_array_iterator;

int pointers()
{
  int x = 5;

  // p points to x
  int* p = &x;
  cout << "x = " << x << endl;

  // change the value of x through p
  *p = 6;
  cout << "x = " << x << endl;
  return 0;
}

string letter_grade(double grade)
{
  // range posts for numeric grades
  static const double numbers[] = {
    97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
  };
  // names for the letter grades
  static const char* const letters[] = {
    "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
  };
  // compute the number of grades given the size of the array
  // and the size of a single element
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
  // given a numeric grade, find and return the associated letter grade
  for (size_t i = 0; i < ngrades; ++i) {
    if (grade >= numbers[i])
      return letters[i];
  }
  return "?\?\?";
}

int copy_file(string in, string out)
{
  ifstream infile(in);
  ofstream outfile(out);
  string s;
  while (getline(infile, s))
    outfile << s << endl;
  return 0;
}

int print_files(int argc, char **argv)
{
  int fail_count = 0;
  // for each file in the input list
  for (int i = 0; i < argc; ++i) {
    ifstream in(argv[i]);
    // if it exists, write its contents, otherwise generate an error message
    if (in) {
      string s;
      while (getline(in, s))
        cout << s << endl;
    }
    else {
      cerr << "cannot open file " << argv[i] << endl;
      ++fail_count;
    }
  }
  return fail_count;
}

char* duplicate_chars(const char* p) {
  // allocate enough space; remember to add one for the null
  size_t length = strlen(p) + 1;
  char* result = new char[length];
  // copy into our newly allocated space and return pointer to first element
  copy(p, p + length, checked_array_iterator<char*>(result, length));
  return result;
}

int ex10_0()
{
  pointers();
  cout << letter_grade(75.0) << endl;
  copy_file("in.txt", "out.txt");
  char* files[] = { "in.txt", "out.txt" };
  print_files(2, files);
  char* str = duplicate_chars("test");
  cout << str << endl;
  return 0;
}