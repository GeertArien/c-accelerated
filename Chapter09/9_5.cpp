/**
Accelerated C++, Exercise 9-5, 9_5.cpp

Write a class and associated functions to generate grades for students who take
the course for pass/fail credit. Assume that only the midterm and final grades matter,
and that a student passes with an average exam score greater than 60. The report
should list the students in alphabetical order, and indicate P or F as the grade.
*/

#include "stdafx.h"
#include "9_5.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::istream;
using std::ostream;
using std::endl;
using std::cin;
using std::cout;

#include <algorithm>
using std::sort;
using std::max;

#include <iterator>

#include "student_info.h"

Grader::Grader(istream& is)
{
  Student_info_p record;

  while (record.read(is)) {
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare_p);
}

ostream& Grader::generate_report(ostream& os) const
{
  vector<Student_info_p>::const_iterator iter = students.begin();
  string::size_type maxlen = 0;
  while (iter != students.end())
    maxlen = max(maxlen, iter++->name().size());
  
  iter = students.begin();
  while (iter != students.end())
  {
    os << iter++->name()
      << string(maxlen + 1 - iter->name().size(), ' ')
      << (iter->passing() ? 'P' : 'F') << endl;
  }

  return os;
}

Student_info_p::Student_info_p() : midterm(0), final(0) { }

Student_info_p::Student_info_p(istream& is) { read(is); }

istream& Student_info_p::read(istream& in)
{
  in >> n >> midterm >> final;
  return in;
}

bool compare_p(const Student_info_p& x, const Student_info_p& y)
{
  return x.name() < y.name();
}

int ex9_5()
{
  Grader g = Grader(cin);
  g.generate_report(cout);
  return 0;
}