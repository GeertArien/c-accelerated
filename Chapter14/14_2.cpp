/**
Accelerated C++, Exercise 14-2, 14_2.cpp

Implement and test the student grading program using Ptr<Core> objects.
*/

#include "stdafx.h"
#include "14_2.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::max;
using std::streamsize;

#include <iomanip>
using std::setprecision;

#include <exception>
using std::domain_error;

#include "student_info.h"
#include "ptr.h"
#include "14_1.h"

int ex14_2()
{
  vector< Ptr<Core> > students; // changed type
  Ptr<Core> record; // changed type
  char ch;
  string::size_type maxlen = 0;
  // read and store the data
  while (cin >> ch) {
    if (ch == 'U')
      record = new Core; // allocate a Core object
    else
      record = new Grad; // allocate a Grad object
    record->read(cin); // Handle<T>::->, then virtual call to read
    maxlen = max(maxlen, record->name().size()); // Handle<T>::->
    students.push_back(record);
  }
  // compare must be rewritten to work on const Handle<Core>&
  sort(students.begin(), students.end(), compare_Core_Ptr);
  // write the names and grades
  for (vector< Ptr<Core> >::size_type i = 0;
    i != students.size(); ++i) {
    // students[i] is a Handle, which we dereference to call the functions
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
    // no delete statement
  }
  return 0;
}
