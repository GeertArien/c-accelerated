/**
Accelerated C++, Exercise 16-0, 16_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "16_0.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "pic.h"
#include "student_info.h"


Picture histogram(const vector<Student_info>& students) {
  Picture names;
  Picture grades;
  // for each student
  for (vector<Student_info>::const_iterator it = students.begin();
    it != students.end(); ++it) {
    // create vertically concatenated pictures of the names and grades
    names = vcat(names, vector<string>(1, it->name()));
    grades = vcat(grades,
      vector<string>(1, " " + string((int)it->grade() / 5, '=')));
  }
  // horizontally concatenate the name and grade pictures to combine them
  return hcat(names, grades);
}int ex16_0()
{
  vector<Student_info> students;
  Student_info s;
  // read the names and grades (U for undergraduate, G for graduate)
  while (s.read(cin))
    students.push_back(s);
  // put the students in alphabetical order
  sort(students.begin(), students.end(), Student_info::compare);
  // write the names and histograms
  cout << frame(histogram(students)) << endl;
  return 0;
}