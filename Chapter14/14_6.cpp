/**
Accelerated C++, Exercise 14-6, 14_6.cpp

The Ptr class really solves two problems: maintaining reference counts, and
allocating and deallocating objects. Define a class that does reference counting and
nothing else; then use that class to reimplement the Ptr class.
*/

#include "stdafx.h"
#include "14_6.h"

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
#include "ptr_r.h"

int ex14_6()
{
  vector< Ptr_r<Core> > students; 
  Ptr_r<Core> record;
  char ch;
  string::size_type maxlen = 0;

  // read and store the data
  while (cin >> ch) {
    if (ch == 'U')
      record = new Core; // allocate a Core object
    else
      record = new Grad; // allocate a Grad object
    record->read(cin); // 
    maxlen = max(maxlen, record->name().size()); 
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare_Core_Ptr_r);

  // write the names and grades
  for (vector< Ptr_r<Core> >::size_type i = 0;
    i != students.size(); ++i) {

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