/**
Accelerated C++, Exercise 13-2, 13_2.cpp

Given the Core and Grad classes defined in this chapter, indicate which function
is called for each of these invocations:

  Core* p1 = new Core;
  Core* p2 = new Grad;
  Core s1;
  Grad s2;

  p1->grade();
  p1->name();

  p2->grade();
  p2->name();

  s1.grade();
  s1.name();

  s2.name();
  s2.grade();

Check whether you are correct by adding output statements to the name and grade
functions that indicate which function is being executed.
*/

#include "stdafx.h"
#include "13_2.h"

#include <iostream>
using std::cin;

#include "student_info.h"

int ex13_2()
{
  // set preprocessor macro "ANNOTATE" in student_info.h to 1

  Core* p1 = new Core;
  Core* p2 = new Grad;
  Core s1;
  Grad s2;

  p1->read(cin); 
  p2->read(cin); 
  s1.read(cin); 
  s2.read(cin);

  p1->grade();
  p1->name();

  p2->grade();
  p2->name();

  s1.grade();
  s1.name();

  s2.name();
  s2.grade();

  delete p1;
  delete p2;

  return 0;
}