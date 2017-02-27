/**
Accelerated C++, Exercise 4-6, 4_6.cpp

Rewrite the Student_info structure to calculate the grades immediately and
store only the final grade.
*/

#include "stdafx.h"
#include "4_6.h"

#include <iostream>
using std::istream;
using std::streamsize;
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <algorithm>
using std::max;
using std::sort;

#include <exception>
using std::domain_error;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "grade.h"

bool compare_students(const Student_info_extra& x, const Student_info_extra& y)
{
  return x.name < y.name;
}

istream& read(istream& is, Student_info_extra& s) 
{
  double midterm, final;
  vector<double> homework;

  is >> s.name >> midterm >> final;
  read_hw(is, homework);

  if (is)
    s.grade = grade(midterm, final, homework);

  return is;
}

int ex4_6()
{
  vector<Student_info_extra> students;
  Student_info_extra record;
  string::size_type maxlen = 0;

  try
  {
    while (read(cin, record))
    {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
    }
  }
  catch (domain_error e) 
  {
    cout << e.what() << endl;
  }

  sort(students.begin(), students.end(), compare_students);

  for (vector<Student_info>::size_type i = 0; i != students.size(); i++)
  {
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
    streamsize prec = cout.precision();
    cout << setprecision(3) << students[i].grade << setprecision(prec);

    cout << endl;
  }

  return 0;
}