/**
Accelerated C++, Exercise 9-4, 9_4.cpp

Rewrite your program from the previous exercise to use the valid function,
thereby avoiding the exception altogether.
*/

#include "stdafx.h"
#include "9_4.h"

#include <iostream>
using std::cout;
using std::endl;

#include "student_info.h"

int ex9_4()
{
  Student_info s;

  if (s.valid())
    s.grade();
  else
    cout << "Invalid input for student." << endl;

  return 0;
}