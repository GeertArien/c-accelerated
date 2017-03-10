#include "stdafx.h"
#include "student_info.h"

#include <vector>
using std::vector;

#include <algorithm>
using std::remove_copy;

#include <iterator>
using std::back_inserter;

#include <exception>
using std::domain_error;

#include <iostream>
using std::istream;

#include <sstream>
using std::stringstream;

#include "grade.h"
#include "vec.h"

double grade_aux(const Student_info& s)
{
  try
  {
    return grade(s);
  }
  catch (domain_error)
  {
    return grade(s.midterm, s.final, 0);
  }
}

double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s)
{
  vector<double> nonzero;

  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else
    return grade(s.midterm, s.final, median(nonzero));
}

istream& read_hw(istream& is, vector<double>& hw)
{
  if (is)
  {
    is.clear();

    double x;
    while (is >> x)
      hw.push_back(x);

    is.clear();
  }

  return is;
}

istream& read(istream& is, Student_info& s)
{
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);

  return is;
}

istream& read(istream& is, vector<Student_info>& v)
{
  const int BUFFSIZE = 80;

  stringstream ss;
  char buff[BUFFSIZE];

  while (is.getline(buff, BUFFSIZE))
  {
    ss << buff;
    Student_info student;
    read(ss, student);
    v.push_back(student);
  }

  return is;
}

vector<Student_info> extract(vector<Student_info>& students, bool criteria(const Student_info&))
{
  vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), criteria);
  vector<Student_info> extracted(iter, students.end());
  students.erase(iter, students.end());

  return extracted;
}

bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}