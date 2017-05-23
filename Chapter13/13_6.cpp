/**
Accelerated C++, Exercise 13-6, 13_6.cpp

Add a class to the system to represent students taking the course for pass/fail
credit. Assume that such students need not do the homework, but might do so. If they
do, the homework should participate in determining whether they passed or failed,
according to the normal formula. If they did no homework, then the grade is the
average of their midterm and final grades. A passing grade is 60 or higher.
*/

#include "stdafx.h"
#include "13_6.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

double Credit::grade() const
{
  if (homework.empty())
    return (midterm + final) / 2.0;
  else
    return Core::grade();
}

int ex13_6()
{
  cout << "Enter a Credit student: " << endl;
  Credit credit(cin);
  cout << "Grade: " << credit.grade() << endl;
  cout << "Passed? " << credit.passed() << endl;

  return 0;
}