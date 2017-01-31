/**
Accelerated C++, Exercise 5-6, 5_6.cpp

Rewrite the extract_fails function from §5.1.1/77 so that instead of erasing
each failing student from the input vector v, it copies the records for the passing
students to the beginning of v, and then uses the resize function to remove the extra
elements from the end of v. How does the performance of this version compare with the
one in §5.1.1/77?
*/

#include "stdafx.h"

#include "5_6.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::steady_clock;

#include "student_info.h"

vector<Student_info> extract_fails_optimised(vector<Student_info>& students) 
{
  vector<Student_info> fail;
  vector<Student_info>::size_type s_size = students.size();
  vector<Student_info>::size_type counter = 0;

  for (vector<Student_info>::size_type i = 0; i < s_size; i++)
  {
    if (fgrade(students[i])) 
    {
      fail.push_back(students[i]);
    }
    else
      students[counter++] = students[i];
  }

  students.resize(counter);

  return fail;
}

int ex5_6() 
{
  string file = "students10000.txt";
  ifstream infile;

  vector<Student_info> students, failed;

  infile.open(file);
  read(infile, students);
  infile.close();
  infile.clear();

  steady_clock::time_point begin = std::chrono::steady_clock::now();
  failed = extract_fails_optimised(students);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  return 0;
}