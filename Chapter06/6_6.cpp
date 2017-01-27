/**
Accelerated C++, Exercise 6-6, 6_6.cpp

Note that the function from the previous exercise and the functions from
§6.2.2/113 and §6.2.3/115 do the same task. Merge these three analysis functions into
a single function.
*/

#include "stdafx.h"

#include "6_6.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::transform;

#include <iterator>
using std::back_inserter;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include "student_info.h"
#include "vec.h"

double analysis(const vector<Student_info>& students, double method(const Student_info&)) 
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), method);
  return median(grades);
}

void write_analysis(ostream& out, const string& name, double method(const Student_info&),
  const vector<Student_info>& did, const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did, method) << ", median(didnt) = " << analysis(didnt, method) << endl;
}

int test_analysis(string file)
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

  write_analysis(cout, "median", grade_aux, did, didnt);
  write_analysis(cout, "average", average_grade, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

  return 0;
}

int ex6_6()
{
  return test_analysis("students10.txt");
}