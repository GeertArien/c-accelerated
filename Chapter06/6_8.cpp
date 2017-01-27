/**
Accelerated C++, Exercise 6-8, 6_8.cpp

Write a single function that can be used to classify students based on criteria of
your choice. Test this function by using it in place of the extract_fails program, and
use it in the program to analyze student grades.
*/

#include "stdafx.h"

#include "6_8.h"

#include <vector>
using std::vector;

#include <algorithm>
using std::stable_partition;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include "student_info.h"
#include "6_6.h"

vector<Student_info> extract(vector<Student_info>& students, bool criteria(const Student_info&)) 
{
  vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), criteria);
  vector<Student_info> extracted(iter, students.end());
  students.erase(iter, students.end());

  return extracted;
}

int test_general_extract(string file) 
{
  vector<Student_info> did, didnt;
  Student_info student;

  ifstream infile;

  infile.open(file);
  read(infile, did);

  didnt = extract(did, did_all_hw);

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

  write_analysis(cout, "median", grade_aux, did, didnt);
  write_analysis(cout, "average", average_grade, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

  return 0;
}

int ex6_8()
{
  return test_general_extract("students10.txt");
}