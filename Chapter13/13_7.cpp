/**
Accelerated C++, Exercise 13-7, 13_7.cpp

Add a class to the system to represent students auditing the course.
*/

#include "stdafx.h"
#include "13_7.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;

istream& Audit::read(istream& in)
{
  in >> n;
  return in;
}

int ex13_7()
{
  cout << "Enter an Audit student: " << endl;
  Audit audit(cin);
  cout << "Grade: " << audit.grade() << endl;
  cout << "Requirements met? " << audit.requirements_met() << endl;

  return 0;
}