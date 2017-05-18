/**
Accelerated C++, Exercise 13-0, 13_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "13_0.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::sort;
using std::max;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

#include <iomanip>
using std::setprecision;

#include <exception>
using std::domain_error;

#include "student_info.h"

int test_method_1()
{
  vector<Core*> students; // store pointers, not objects
  Core* record; // temporary must be a pointer as well
  char ch;
  string::size_type maxlen = 0;
  // read and store the data
  while (cin >> ch) {
    if (ch == 'U')
      record = new Core; // allocate a Core object
    else
      record = new Grad; // allocate a Grad object
    record->read(cin); // virtual call
    maxlen = max(maxlen, record->name().size()); // dereference
    students.push_back(record);
  }
  // pass the version of compare that works on pointers
  sort(students.begin(), students.end(), compare_Core_ptrs);
  // write the names and grades
  for (vector<Core*>::size_type i = 0;
    i != students.size(); ++i) {
    // students[i] is a pointer that we dereference to call the functions
    cout << students[i]->name()
      << string(maxlen + 1 - students[i]->name().size(), ' ');
    try {
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    }
    catch (domain_error e) {
      cout << e.what() << endl;
    }
    delete students[i]; // free the object allocated when reading
  }
  return 0;
}

int test_method_2()
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
  sort(students.begin(), students.end(), Student_info::compare);
  // write the names and grades
  for (vector<Student_info>::size_type i = 0;
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

int ex13_0()
{
  cout << "First method" << endl;
  test_method_1();
  cout << "Second method" << endl;
  cin.clear();
  test_method_2();

  return 0;
}