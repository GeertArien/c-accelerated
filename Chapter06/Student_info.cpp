#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "student_info.h"
#include "grade.h"
#include "vec.h"

using std::cout;          using std::cin;
using std::endl;          using std::domain_error;
using std::istream;       using std::vector;
using std::transform;     using std::back_inserter;
using std::ostream;       using std::string;
using std::remove_copy;   using std::remove_copy_if;
using std::remove_if;     using std::stable_partition;
using std::stringstream;

bool compare(const Student_info& x, const Student_info& y) 
{
  return x.name < y.name;
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

istream& read(istream& is, Student_info& s) 
{
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);

  return is;
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

bool did_all_hw(const Student_info& s) 
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}

double average_analysis(const vector<Student_info>& students) 
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), average_grade);
  return median(grades);
}

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

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&),
  const vector<Student_info>& did, const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
  vector<Student_info> fail;
  remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
  students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

  return fail;
}

bool fgrade(const Student_info& s) 
{
  return grade(s) < 60;
}

bool pgrade(const Student_info& s) 
{
  return !fgrade(s);
}