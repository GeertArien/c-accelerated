// Chapter03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::vector;  using std::sort;

void StudentGradeAverage() {
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

  while (cin >> x) {
    ++count;
    sum += x;
  }

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
    << setprecision(prec) << endl;
}

int StudentGradeMedium() {
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

  if (size == 0) {
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

int main()
{
  return StudentGradeMedium();
}

