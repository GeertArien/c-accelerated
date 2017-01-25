/**
Accelerated C++, Exercise 7-2, 7_2.cpp

Extend the program in §4.2.3/64 to assign letter grades by ranges:
  A 90-100
  B 80-89.99...
  C 70-79.99...
  D 60-69.99...
  F < 60
The output should list how many students fall into each category.
*/

#include "stdafx.h"

#include "7_2.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;   using std::cout;
using std::endl;  using std::streamsize;

#include <iomanip>
using std::setprecision;

#include <algorithm>
using std::max;

#include <exception>
using std::domain_error;

#include <map>
using std::map;

#include "student_info.h"
#include "grade.h"


vector<Student_info> read_and_grade() 
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) 
  {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); i++) 
  {
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

    try 
    {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    }
    catch (domain_error e)
    {
      cout << e.what();
    }
    cout << endl;
  }

  return students;
}

int grade_by_range() 
{
  const vector<Student_info> students = read_and_grade();
  map<char, int> graded_students;

  for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter)
  {
    if (iter->grade >= 90)
      ++graded_students['A'];
    else if (iter->grade >= 80)
      ++graded_students['B'];
    else if (iter->grade >= 70)
      ++graded_students['C'];
    else if (iter->grade >= 60)
      ++graded_students['D'];
    else
      ++graded_students['F'];
  }

  for (map<char, int>::const_iterator iter = graded_students.begin(); iter != graded_students.end(); ++iter)
  {
    cout << iter->first << " : " << iter->second << " students" << endl;
  }

  return 0;
}

int ex7_2() 
{
  return grade_by_range();
}
