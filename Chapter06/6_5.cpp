/**
Accelerated C++, Exercise 6-5, 6_5.cpp

Use a library algorithm to concatenate all the elements of a vector<string>.
*/

#include "stdafx.h"

#include "6_5.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::transform;

#include <iterator>
using std::back_inserter;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include "student_info.h"
#include "vec.h"

double optimistic_median_analysis(const vector<Student_info>& students) 
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
  return median(grades);
}

int test_optimistic_median(string file)
{
  vector<Student_info> students, did, didnt;
  Student_info student;

  ifstream infile;

  infile.open(file);
  read(infile, students);

  for (vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++)
  {
    if (did_all_hw(*it))
      did.push_back(*it);
    else
      didnt.push_back(*it);
  }

  if (did.empty()) 
  {
    cout << "No student did all the homework!" << endl;
    return 1;
  }

  if (didnt.empty()) 
  {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

  return 0;
}

int ex6_5()
{
  return test_optimistic_median("students10.txt");
}