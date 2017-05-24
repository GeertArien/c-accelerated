/**
Accelerated C++, Exercise 14-3, 14_3.cpp

Implement the Student_info class to use the final version of Ptr, and use that
version to implement the grading program from §13.5/247.
*/

#include "stdafx.h"
#include "14_3.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

#include <iomanip>
using std::setprecision;

#include <algorithm>
using std::max;

#include <exception>
using std::domain_error;

#include "student_info_p.h"

int ex14_3()
{
  vector<Student_info_p> students;
  Student_info_p record;
  string::size_type maxlen = 0;
  // read and store the data
  while (record.read(cin)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }
  // alphabetize the student records
  sort(students.begin(), students.end(), Student_info_p::compare);
  // write the names and grades
  for (vector<Student_info_p>::size_type i = 0;
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