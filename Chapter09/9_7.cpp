/**
Accelerated C++, Exercise 9-7, 9_7.cpp

The read_hw function §4.1.3/57 solves a general problem (reading a sequence of
values into a vector) even though its name suggests that it should be part of the
implementation of Student_info. Of course, we could change its name—but suppose,
instead, that you wanted to integrate it with the rest of the Student_info code, in
order to clarify that it was not intended for public access despite its apparent generality?
How would you do so?
*/

#include "stdafx.h"
#include "9_7.h"

#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;

#include <vector>

#include "student_info.h"

Student_info_hw::Student_info_hw() : midterm(0), final(0) { }

Student_info_hw::Student_info_hw(istream& is) { read(is); }

istream& Student_info_hw::read(istream& in)
{
  in >> n >> midterm >> final;
  read_hw(in);
  return in;
}

istream& Student_info_hw::read_hw(istream& is)
{
  if (is)
  {
    is.clear();

    double x;
    while (is >> x)
      homework.push_back(x);

    is.clear();
  }

  return is;
}

double Student_info_hw::grade() const
{
  return ::grade(midterm, final, homework);
}

int ex9_7()
{
  Student_info_hw student(std::cin);
  cout << student.name() << ": " << student.grade() << endl;
  return 0;
}