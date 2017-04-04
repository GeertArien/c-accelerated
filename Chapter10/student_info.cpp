#include "stdafx.h"
#include "student_info.h"

#include <iostream>
using std::istream;

#include <vector>
using std::vector;

#include <exception>
using std::domain_error;

#include <algorithm>
using std::sort;

Student_info::Student_info() : midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }

istream& Student_info::read(istream& in)
{
  in >> n >> midterm >> final;
  read_hw(in, homework);
  return in;
}

double Student_info::grade() const
{
  return ::grade(midterm, final, homework);
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

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("Student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
  return 0.2 *midterm + 0.4 * final + 0.4 * homework;
}

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name() < y.name();
}

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0)
    throw domain_error("median of empty vector");

  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}