/**
Accelerated C++, Exercise 9-1, 9_1.cpp

Reimplement the Student_info class so that it calculates the final grade when
reading the student's record, and stores that grade in the object. Reimplement the
grade function to use this precomputed value.
*/

#include "stdafx.h"
#include "9_1.h"

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

#include <string>
using std::string;

#include <iomanip>
using std::setprecision;

#include "student_info.h"

Student_info_alt::Student_info_alt() : g(0) { }

Student_info_alt::Student_info_alt(istream& is) { read(is); }

istream& Student_info_alt::read(istream& in)
{
  try
  {
    double midterm, final;
    vector<double> homework;
    in >> n >> midterm >> final;
    read_hw(in, homework);
    g = ::grade(midterm, final, homework);
  }
  catch (domain_error e) { }
  return in;
}

int ex9_1()
{
  vector<Student_info_alt> students;
  Student_info_alt record;
  string::size_type maxlen = 0;

  while (record.read(cin)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  for (vector<Student_info_alt>::size_type i = 0;
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