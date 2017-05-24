/**
Accelerated C++, Exercise 14-0, 14_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "14_0.h"

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

#include "student_info.h"
#include "handle.h"
#include "str.h"

bool compare_Core_handles(const Handle<Core> hc1, const Handle<Core> hc2)
{
  return compare(*hc1, *hc1);
}

int test_handle()
{
  vector< Handle<Core> > students; // changed type
  Handle<Core> record; // changed type
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
  sort(students.begin(), students.end(), compare_Core_handles);
  // write the names and grades
  for (vector< Handle<Core> >::size_type i = 0;
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

int test_str()
{
  Str s1 = "Hello ";
  Str s2;
  cout << "Please enter your name: ";
  cin >> s2;
  Str s3 = s1 + s2 + " how are you?";
  cout << s3 << endl;

  return 0;
}

int ex14_0()
{
  test_handle();
  cin.clear();
  test_str();

  return 0;
}