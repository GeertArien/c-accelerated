/**
Accelerated C++, Exercise 9-6, 9_6.cpp

Rewrite the grading program for the pass/fail students so that the report shows all
the students who passed, followed by all the students who failed.
*/

#include "stdafx.h"
#include "9_6.h"

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
using std::stable_partition;
using std::copy;

#include <iterator>

#include "student_info.h"

bool passing(const Student_info_p s)
{
  return s.passing();
}

Grader_ext::Grader_ext(istream& is)
{
  Student_info_p record;

  while (record.read(is)) {
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare_p);
}

ostream& Grader_ext::generate_report(ostream& os)
{
  vector<Student_info_p> students_copy(students);
  const vector<Student_info_p>::iterator iter = stable_partition(students_copy.begin(), students_copy.end(), passing);

  generate_report(os, students_copy.begin(), iter);
  generate_report(os, iter, students_copy.end());

  return os;
}

ostream& Grader_ext::generate_report(ostream& os,
  vector<Student_info_p>::const_iterator begin, vector<Student_info_p>::const_iterator end) const
{
  vector<Student_info_p>::const_iterator iter = begin;
  string::size_type maxlen = 0;
  while (iter != end)
    maxlen = max(maxlen, iter++->name().size());

  while (begin != end)
  {
    os << begin++->name()
      << string(maxlen + 1 - begin->name().size(), ' ')
      << (begin->passing() ? 'P' : 'F') << endl;
  }

  return os;
}

int ex9_6()
{
  Grader_ext g = Grader_ext(cin);
  g.generate_report(cout);
  return 0;
}