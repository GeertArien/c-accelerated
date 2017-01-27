/**
Accelerated C++, Exercise 6-7, 6_7.cpp

The portion of the grading analysis program from §6.2.1/110 that read and
classified student records depending on whether they did (or did not) do all the
homework is similar to the problem we solved in extract_fails. Write a function to
handle this subproblem.
*/

#include "stdafx.h"

#include "6_7.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::stable_partition;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include "student_info.h"


vector<Student_info> extract_not_all_hw(vector<Student_info>& students) 
{
  vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), did_all_hw);
  vector<Student_info> not_all_hw(iter, students.end());
  students.erase(iter, students.end());

  return not_all_hw;
}

int test_extract(string file)
{
  vector<Student_info> did, didnt;
  Student_info student;

  ifstream infile;

  infile.open(file);
  read(infile, did);

  didnt = extract_not_all_hw(did);

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

  return 0;
}

int ex6_7()
{
  return test_extract("students10.txt");
}