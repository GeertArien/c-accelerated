/**
Accelerated C++, Exercise 13-4, 13_4.cpp

Add to these classes a function that will map a numeric grade to a letter grade
according to the grading policy outlined in §10.3/177.
*/

#include "stdafx.h"
#include "13_4.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "student_info.h"

int ex13_4()
{
  cout << "Enter a Core student: " << endl;
  Core core(cin);
  cout << "Grade: " << core.letter_grade() << endl;

  cout << "Enter a Grad student: " << endl;
  Grad grad(cin);
  cout << "Grade: " << grad.letter_grade() << endl;

  return 0;
}