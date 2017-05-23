/**
Accelerated C++, Exercise 13-1, 13_1.cpp

Annotate the Core and Grad constructors to write the constructor's name and
argument list when the constructor is executed. For example, you should add a
statement such as

  cerr << "Grad::Grad(istream&)" << endl;

to the Grad constructor taking an istream& parameter. Then write a small program
that exercises each constructor. Predict beforehand what the output will be. Revise your
program and predictions until your predictions match what is actually written.
*/

#include "stdafx.h"
#include "13_1.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "student_info.h"

int ex13_1()
{
  // set preprocessor macro "ANNOTATE" in student_info.h to 1

  Core core1;
  Grad grad1;

  cout << "Enter Core student info:" << endl;
  Core core2(cin);

  cout << "Enter Grad student info:" << endl;
  Grad grad2(cin);

  return 0;
}