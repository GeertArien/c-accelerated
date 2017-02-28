/**
Accelerated C++, Exercise 3-5, 3_5.cpp

Write a program that will keep track of grades for several students at once. The
program could keep two vectors in sync: The first should hold the student's names,
and the second the final grades that can be computed as input is read. For now, you
should assume a fixed number of homework grades. We'll see in §4.1.3/56 how to
handle a variable number of grades intermixed with student names.
*/

#include "stdafx.h"
#include "3_5.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

#include <iomanip>
using std::setprecision;

int StudentGradeAverage(double& result, string& name)
{
  cout << "Please enter your name: ";
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

  result = 0.2 * midterm + 0.4 * final + 0.4 * homework;

  return 0;
}

void OuputGradeAverage(double grade)
{
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << grade << setprecision(prec) << endl;
}

int StudentNamesGrades()
{
  vector<string> names;
  vector<double> grades;
  string answer;

  do 
  {
    string name;
    double grade;
    if (StudentGradeAverage(grade, name))
      return 1;

    names.push_back(name);
    grades.push_back(grade);

    cout << "Enter (y)es if you want to enter more grades and students: ";
    cin.clear();
    cin >> answer;
    cout << endl;
  } 
  while (answer.at(0) == 'y' || (answer.at(0) == 26 && answer.at(1) == 'y'));

  for (vector<string>::size_type i = 0; i < names.size(); i++)
  {
    cout << names[i] << ":" << endl;
    OuputGradeAverage(grades[i]);
    cout << endl;
  }

  return 0;
}

int ex3_5() 
{
  return StudentNamesGrades();
}