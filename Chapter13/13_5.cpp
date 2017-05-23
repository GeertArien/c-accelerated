/**
Accelerated C++, Exercise 13-5, 13_5.cpp

Add to these classes a function that will map a numeric grade to a letter grade
according to the grading policy outlined in §10.3/177.
*/

#include "stdafx.h"
#include "13_5.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "student_info.h"

int ex13_5()
{
  cout << "Enter a Core student: " << endl;
  Core core(cin);
  cout << "Requirements met? " << core.requirements_met() << endl;

  cout << "Enter a Grad student: " << endl;
  Grad grad(cin);
  cout << "Requirements met? " << grad.requirements_met() << endl;

  return 0;
}