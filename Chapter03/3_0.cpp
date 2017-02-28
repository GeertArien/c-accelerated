/**
Accelerated C++, Exercise 3-0, 3_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "3_0.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

#include <iomanip>
using std::setprecision;

#include <algorithm>
using std::sort;

void StudentGradeAverage() 
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

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
    << setprecision(prec) << endl;
}

int StudentGradeMedian() 
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

  double x;
  vector<double> homework;

  while (cin >> x)
    homework.push_back(x);

  typedef vector<double>::size_type vector_size;
  vector_size size = homework.size();

  if (size == 0)
  {
    cout << endl << "You must enter your grades. "
      "Please try again." << endl;
    return 1;
  }

  sort(homework.begin(), homework.end());

  vector_size mid = size / 2;
  double median = size % 2 == 0 ? (homework[mid - 1] + homework[mid]) / 2 : homework[mid];

  double result = 0.2 * midterm + 0.4 * final + 0.4 * median;

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << result << setprecision(prec) << endl;

  return 0;
}

int ex3_0()
{
  cout << "Grade average:" << endl;
  StudentGradeAverage();
  cin.clear();
  cout << "Grade median:" << endl;
  return StudentGradeMedian();
}