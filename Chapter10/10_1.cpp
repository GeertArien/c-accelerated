/**
Accelerated C++, Exercise 10-1, 10_1.cpp

Rewrite the student-grading program from §9.6/166 to generate letter grades.
*/

#include "stdafx.h"
#include "10_1.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::max;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <exception>
using std::domain_error;

#include "student_info.h"
#include "10_0.h"

int ex10_1()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;
  // read and store the data
  while (record.read(cin)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }
  // alphabetize the student records
  sort(students.begin(), students.end(), compare);
  // write the names and grades
  for (vector<Student_info>::size_type i = 0;
    i != students.size(); ++i) {
    cout << students[i].name()
      << string(maxlen + 1 - students[i].name().size(), ' ');
    try {
      double final_grade = students[i].grade();
      cout << letter_grade(final_grade) << endl;
    }
    catch (domain_error e) {
      cout << e.what() << endl;
    }
  }
  return 0;
}