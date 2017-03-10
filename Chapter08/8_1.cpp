/**
Accelerated C++, Exercise 8-1, 8_1.cpp

Note that the various analysis functions we wrote in §6.2/110 share the same
behavior; they differ only in terms of the functions they call to calculate the final grade.
Write a template function, parameterized by the type of the grading function, and use
that function to evaluate the grading schemes.
*/

#include "stdafx.h"
#include "8_1.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::back_inserter;

#include <algorithm>
using std::transform;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include "student_info.h"
#include "vec.h"

template <class F>
double analysis(const vector<Student_info>& students, F grading_method)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grading_method);
  return median(grades);
}

template <class F>
void write_analysis(ostream& out, const string& name, F grading_method,
  const vector<Student_info>& did, const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did, grading_method) << ", median(didnt) = " << analysis(didnt, grading_method) << endl;
}

int ex8_1()
{
  vector<Student_info> did, didnt;
  Student_info student;

  ifstream infile;

  infile.open("students10.txt");
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