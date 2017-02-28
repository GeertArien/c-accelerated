/**
Accelerated C++, Exercise 3-6, 3_6.cpp

The average-grade computation in §3.1/36 might divide by zero if the student
didn't enter any grades. Division by zero is undefined in C++, which means that the
implementation is permitted to do anything it likes. What does your C++
implementation do in this case? Rewrite the program so that its behavior does not
depend on how the implementation treats division by zero.
*/

#include "stdafx.h"
#include "3_6.h"

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

#include <iomanip>
using std::setprecision;

void StudentGradeAverageRobust() 
{
  cout << "Please enter your name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all your homework grades, "
    "followed by end-of-file: ";

  int count = 0;
  double sum = 0;
  double x;

  while (cin >> x) 
  {
    ++count;
    sum += x;
  }

  double homework = count == 0 ? 0 : sum / count;

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << 0.2 * midterm + 0.4 * final + 0.4 * homework
    << setprecision(prec) << endl;
}

int ex3_6()
{
  StudentGradeAverageRobust();

  return 0;
}