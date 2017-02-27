/**
Accelerated C++, Exercise 4-0, 4_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "4_0.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::streamsize;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <algorithm>
using std::sort;
using std::max;

#include <exception>
using std::domain_error;

#include "student_info.h"
#include "grade.h"

int ex4_0()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record))
  {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); i++) 
  {
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

    try 
    {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    }
    catch (domain_error e) 
    {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}
