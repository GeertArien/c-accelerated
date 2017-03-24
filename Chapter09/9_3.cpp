/**
Accelerated C++, Exercise 9-3, 9_3.cpp

Our grade function was written to throw an exception if a user tried to calculate a
grade for a Student_info object whose values had not yet been read. Users who care
are expected to catch this exception. Write a program that triggers the exception but
does not catch it. Write a program that catches the exception.
*/

#include "stdafx.h"
#include "9_3.h"

#include <exception>
using std::exception;

#include <iostream>
using std::cout;
using std::endl;

#include "student_info.h"

int ex9_3()
{
  Student_info s;

  try
  {
    s.grade();
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }

  return 0;
}