/**
Accelerated C++, Exercise 9-2, 9_2.cpp

If we define the name function as a plain, nonconst member function, what other
functions in our system must change and why?
*/

#include "stdafx.h"
#include "9_2.h"

#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

#include <vector>
using std::vector;

#include <exception>
using std::domain_error;

#include <algorithm>
using std::max;
using std::sort;

#include <string>
using std::string;

#include <iomanip>
using std::setprecision;

#include "student_info.h"

Student_info_n::Student_info_n() : g(0) { }

Student_info_n::Student_info_n(istream& is) { read(is); }

istream& Student_info_n::read(istream& in)
{
  try
  {
    double midterm, final;
    vector<double> homework;
    in >> n >> midterm >> final;
    read_hw(in, homework);
    g = ::grade(midterm, final, homework);
  }
  catch (domain_error e) {}
  return in;
}

// compare function added for not constant student_info_n objects
// not constant objects can't access functions that are not defined as constant
bool compare_n(Student_info_n& x,  Student_info_n& y)
{
  return x.name() < y.name();
}

int ex9_2()
{
  vector<Student_info_n> students;
  Student_info_n record;
  string::size_type maxlen = 0;

  while (record.read(cin)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare_n);

  for (vector<Student_info_n>::size_type i = 0;
    i != students.size(); ++i) {
    cout << students[i].name()
      << string(maxlen + 1 - students[i].name().size(), ' ');
    try {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    }
    catch (domain_error e) {
      cout << e.what() << endl;
    }
  }
  return 0;
}