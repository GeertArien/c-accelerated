/**
Accelerated C++, Exercise 13-3, 13_3.cpp

The class that we built in Chapter 9 included a valid member that allowed users
to check whether the object held values for a student record or not. Add that
functionality to the inheritance-based system of classes.
*/

#include "stdafx.h"
#include "13_3.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "student_info.h"

int ex13_3()
{
  Grad grad(cin);

  if (grad.valid())
    cout << "Grade: " << grad.grade() << endl;

  return 0;
}